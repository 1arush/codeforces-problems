#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int n=s.length();
    vector<int>dp(n+1);
    if(s[0]==s[1]) dp[1]=1;
    else dp[1]=0;
    for(int i=1;i<n-1;i++){
        if(s[i]==s[i+1]) dp[i+1]=dp[i]+1;
        else dp[i+1]=dp[i];
    } dp[n]=dp[n-1];
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<'\n';
    }
}