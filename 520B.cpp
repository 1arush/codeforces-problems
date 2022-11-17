#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x; return 0; }
int n,m;
int F(int a, vector<int>&dp){
    if(a==n) return 0;
    if(a<n) return n-a;
    if(a%2) dp[a]=F(a+1,dp)+1;
    else dp[a]=F(a/2,dp)+1;
    return dp[a];
}
int main(){
    cin>>n>>m;
    if(n>=m) print(n-m)
    vector<int>dp(10002);
    dp[n]=F(m,dp);
    cout<<dp[n];
}