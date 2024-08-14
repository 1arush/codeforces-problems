#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n, k;
        cin>>n>>k;
        vector<int> a(n+1), b(n+1);
        vector<vector<int>> t(n+1,vector<int>(201,1e9));
        for(int i=1, x, y; i<=n; ++i){
                cin>>x>>y;
                if(x>y) swap(x,y);
                a[i]=x, b[i]=y;
                int cnt=0, cost=0;
                while(cnt<k){
                        if(!x && !y) break;
                        if(x>y) swap(x,y);
                        cnt++, cost+=x, --y;
                        t[i][cnt]=cost;
                }
        }        
        vector<vector<int>> dp(n+1,vector<int>(k+1,1e9));
        dp[0][0]=0;
        // dp[i][k] = min ops to color get at least score k on i-th prefix
        for(int i=1; i<=n; ++i){
                dp[i][0]=dp[i-1][0];
                for(int j=1; j<=k; ++j){
                        // how many do I give to this guy?
                        dp[i][j]=dp[i-1][j];
                        for(int x=1; x<=k; ++x){
                                if(j-x>=0) dp[i][j]=min(dp[i][j],dp[i-1][j-x]+t[i][x]);
                                else dp[i][j]=min(dp[i][j],t[i][x]);
                        }
                }
                for(int j=k-1; j>=0; --j){
                        dp[i][j]=min(dp[i][j],dp[i][j+1]);
                }
        }
        int ans=dp[n][k];
        if(ans==1e9){
                cout<<"-1\n"; return;
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
