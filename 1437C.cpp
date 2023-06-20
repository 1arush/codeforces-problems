#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n), b(2*n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(),a.end());
        for(int i=0; i<2*n; i++) b[i]=i+1;
        int dp[n+1][2*n+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=2*n; j++) dp[i][j]=1e9;
        }
        for(int i=0; i<=2*n; i++) dp[0][i]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=2*n; j++){
                dp[i][j]=dp[i][j-1];
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i-1]-b[j-1]));
            }
        }
        cout<<dp[n][2*n]<<'\n';
    }
    return 0;
}