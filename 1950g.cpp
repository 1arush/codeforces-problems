#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main(){
        cin.tie(0)->sync_with_stdio(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                int n;
                cin>>n;
                map<string,int> mp;
                vector<int> a(n), b(n);
                for(int i=0; i<n; ++i){
                        string x,y;
                        cin>>x>>y;
                        int sz=mp.size();
                        if(mp.find(x)==mp.end()) mp[x]=sz++;
                        if(mp.find(y)==mp.end()) mp[y]=sz++;
                        a[i]=mp[x], b[i]=mp[y];
                }
                vector<vector<bool>> dp(1<<n, vector<bool>(n));
                for(int i=0; i<n; ++i){
                        dp[1<<i][i]=1;
                }
                int ans=0;
                for(int mask=0; mask<(1<<n); ++mask){
                        for(int i=0; i<n; ++i){
                                if(!(mask>>i&1)) continue;
                                for(int j=0; j<n; ++j){
                                        if(mask>>j&1) continue;
                                        if(a[i]!=a[j] && b[i]!=b[j]) continue;
                                        if(dp[mask][i]) dp[mask|(1<<j)][j]=1;
                                }
                                if(dp[mask][i]) ans=max(ans,(int)__builtin_popcount(mask));
                        }
                }
                cout<<n-ans<<'\n';
        }
    return 0;
}
