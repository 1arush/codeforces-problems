#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf=1e9;

void solve_test(){
        int n;
        cin>>n;
        vector<int> h(n), dp(n,inf);
        for(int i=0; i<n; ++i){
                cin>>h[i];
        }
        dp[0]=0;
        for(int i=1; i<n; ++i){
                if(i-1>=0) dp[i]=min(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
                if(i-2>=0) dp[i]=min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
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
