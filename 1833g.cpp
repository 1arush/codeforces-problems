#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<vector<int>> gr;
vector<int> dp;
vector<pair<int,int>> edg;

void dfs(int u, int p){
        dp[u]=1;
        for(int v:gr[u]){
                if(v==p) continue;
                dfs(v,u);
                dp[u]+=dp[v];
                if(dp[v]==0){
                        edg.emplace_back(u,v);
                }
        }
        if(dp[u]==3) dp[u]=0;
}

void solve(){
        // we will remove i, dp[i]=3
        int n;
        cin>>n;
        gr=vector<vector<int>> (n);
        dp=vector<int> (n);
        edg.clear();
        map<pair<int,int>,int> mp;
        for(int i=1, u, v; i<n; ++i){
                cin>>u>>v, --u, --v;
                gr[u].push_back(v);
                gr[v].push_back(u);
                mp[{u,v}]=i;
        }
        dfs(0,-1);
        if(dp[0]){
                cout<<"-1\n"; return;
        }
        cout<<(int)edg.size()<<'\n';
        for(auto [l,r]:edg){
                if(mp.find({l,r})!=mp.end()){
                        cout<<mp[{l,r}]<<' ';
                }else{
                        cout<<mp[{r,l}]<<' ';
                }
        }
        cout<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                solve();
        }
        return 0;
}
