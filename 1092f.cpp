#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> a, s, dp;
vector<vector<int>> gr;
int ans=0;

void dfs(int u, int p){
        s[u]=a[u], dp[u]=0;
        for(int v:gr[u]){
                if(v==p) continue;
                dfs(v,u);
                s[u]+=s[v];
                dp[u]+=dp[v]+s[v];
        }
}

void reroot(int u, int p){
        ans=max(ans,dp[u]);
        for(int v:gr[u]){
                if(v==p) continue;
                int root=dp[u], child=dp[v];
                int up=s[u], down=s[v];
                dp[u]-=dp[v]+s[v]; // lose a subtree
                dp[v]+=dp[u]+(s[u]-s[v]);
                s[u]-=s[v], s[v]+=s[u];
                reroot(v,u);
                dp[u]=root, dp[v]=child;
                s[u]=up, s[v]=down;
        }
}

int32_t main(){
        cin.tie(0)->sync_with_stdio(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int n;
        cin>>n;
        gr=vector<vector<int>> (n);
        a=vector<int> (n);
        s=vector<int> (n);
        dp=vector<int> (n);
        for(auto &x:a) cin>>x;
        for(int i=1, u, v; i<n; ++i){
                cin>>u>>v, --u, --v;
                gr[u].push_back(v);
                gr[v].push_back(u);
        }
        dfs(0,-1);
        reroot(0,-1);
        cout<<ans<<'\n';
        return 0;
}
