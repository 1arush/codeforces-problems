#include <bits/stdc++.h>
#define int long long
using namespace std;

struct unionfind {
        vector<int> sz, p;
        unionfind(int n){
                sz.assign(n,1), p.resize(n);
                iota(p.begin(),p.end(),0);
        }
        int leader(int a){
                return (a==p[a] ? a : p[a]=leader(p[a]));
        }
        bool same(int a, int b){
                a=leader(a), b=leader(b);
                return a==b;
        }
        void unite(int a, int b){  // union by size
                a=leader(a), b=leader(b);
                if(sz[a]<sz[b]) swap(a,b);
                if(a!=b) p[b]=a, sz[a]+=sz[b];
        }
};

vector<vector<int>> gr;
vector<pair<int,int>> edg;
vector<int> tin, low, vis, dep;
int t;

void dfs(int u, int p, unionfind& dsu){
        vis[u]=1;
        tin[u]=low[u]=t++;
        for(int v:gr[u]){
                if(v==p) continue;
                if(vis[v]){
                        low[u]=min(low[u],tin[v]);  
                        dsu.unite(u,v);     
                }else{
                        dfs(v,u,dsu);
                        low[u]=min(low[u],low[v]);
                        if(low[v]>tin[u]){  
                                edg.emplace_back(u,v);
                                // bridge :: back-edge iff low[v]<=tin[u]
                        }else{
                                dsu.unite(u,v);
                        }
                }
        }
}

void dfs2(int u, int p){
        for(int v:gr[u]){
                if(v==p) continue;
                dep[v]=dep[u]+1;
                dfs2(v,u);
        }
}

void solve_test(){
        int n, m;
        cin>>n>>m;
        gr=vector<vector<int>> (n);
        tin=vector<int> (n);
        low=vector<int> (n);
        vis=vector<int> (n);
        while(m--){
                int u, v;
                cin>>u>>v, --u, --v;
                gr[u].push_back(v);
                gr[v].push_back(u);
        }
        unionfind dsu(n);
        dfs(0,-1,dsu);
        for(int i=0; i<n; ++i){
                gr[i].clear();
                vis[i]=0;
        }
        for(auto [x,y]:edg){
                x=dsu.leader(x), y=dsu.leader(y);
                gr[x].push_back(y);
                gr[y].push_back(x);
        }
        // now it is definitely a tree
        // find the diameter of the tree
        dep=vector<int> (n);
        for(int i=0; i<n; ++i){
                if(!vis[i] && !gr[i].empty()){
                        dep[i]=0;
                        dfs2(i,-1);
                        break;
                }
        }
        int far=0;
        for(int i=0; i<n; ++i){
                if(dep[i]>dep[far]) far=i;
        }
        dep=vector<int> (n);
        dfs2(far,-1);
        int ans=*max_element(dep.begin(),dep.end());
        cout<<ans<<'\n';
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
