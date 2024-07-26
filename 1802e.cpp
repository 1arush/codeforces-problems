#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n;
        cin>>n;
        vector<vector<int>> G(n);
        vector<int> vec;
        for(int i=0, sz; i<n; ++i){
                cin>>sz;
                for(int j=0, x; j<sz; ++j){
                        cin>>x;
                        if(G[i].empty() || x>G[i].back()){
                                G[i].push_back(x);
                        }
                }
        }        
        // exchange argument
        sort(G.begin(),G.end(),[&](vector<int>& a, vector<int>& b){
                return a.back()<b.back();
        });
        // don't need segtree, think of a better approach
        // don't force datastructures like a noob!
        vector<int> dp(n);
        for(int i=0; i<n; ++i){
                vec.push_back(G[i].back());
                if(i) dp[i]=dp[i-1];
                int sz=G[i].size();
                dp[i]=max(dp[i],sz);
                for(int j=0; j<sz; ++j){
                        int v=G[i][j];
                        // we want [v...] to be a part
                        int ls=lower_bound(vec.begin(),vec.end(),v)-vec.begin();
                        if(ls){
                                dp[i]=max(dp[i],sz-j+dp[ls-1]);
                        }
                }
        }
        int ans=dp[n-1];
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
