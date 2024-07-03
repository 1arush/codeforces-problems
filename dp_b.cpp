#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

void solve_test(){
        int n, k;
        cin>>n>>k;
        vector<int> h(n), dp(n,inf);
        for(int i=0; i<n; ++i){
                cin>>h[i];
        }
        dp[0]=0;
        for(int i=1; i<n; ++i){
                for(int j=i-1; j>=max(0,i-k); --j){
                        dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
                }
        }
        cout<<dp[n-1]<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        // cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
