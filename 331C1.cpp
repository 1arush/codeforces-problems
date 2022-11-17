#include <bits/stdc++.h>
using namespace std;
int gen(int n, vector<int>&dp){
    if(n==0) return 0;
    else if(n/10==0) return 1;
    string A=to_string(n);
    for(int i=0;i<A.length();i++){
        if(A[i]=='0') continue;
        int k=A[i]-48;
        if(dp[n-k]==1e+7) dp[n-k]=gen(n-k,dp);
        dp[n]=min(dp[n],dp[n-k]);
    }
    return dp[n]+1;
}
int main(){
    int n; cin>>n;
    vector<int>dp(n+1);
    for(int i=0;i<=n;i++) dp[i]=1e+7;
    cout<<gen(n,dp)<<'\n';
}