#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// finding bridges offline in O(n+m) using DFS

vector<vector<int>> gr;
vector<int> tin, low, vis, sub, ful;
int t, c, f;

void dfs(int u, int p){
        vis[u]=sub[u]=1;
        if(p!=-1) ful[u]=ful[p];
        tin[u]=low[u]=t++;
        for(int v:gr[u]){
                if(v==p) continue;
                if(!vis[v]){
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        sub[u]+=sub[v];
                        if(low[v]>tin[u]){  
                                // cout<<u<<' '<<v<<'\n';
                                int o=ful[u];
                                int old=o*(o-1)/2;
                                int n1=o-sub[v], n2=sub[v];
                                f=min(f,n1*(n1-1)/2+n2*(n2-1)/2-old);
                                // bridge found -> back-edge iff low[v]<=tin[u]
                        }
                }else{
                        low[u]=min(low[u],tin[v]);
                }
        }
}

int get_size(int u){
        vis[u]=1;
        int r=1;
        for(int v:gr[u]){
                if(!vis[v]){
                        r+=get_size(v);
                }
        }
        return r;
}

void solve_test(){
        int n, m;
        cin>>n>>m;
        t=f=0; 
        gr=vector<vector<int>>(n);
        tin=vector<int>(n);
        sub=vector<int>(n);
        vis=vector<int>(n);
        ful=vector<int>(n);
        low=vector<int>(n);
        for(int i=0; i<m; ++i){
                int u, v;
                cin>>u>>v, --u, --v;
                gr[u].push_back(v);
                gr[v].push_back(u);
        }
        for(int i=0; i<n; ++i){
                if(!vis[i]){
                        ful[i]=get_size(i);
                }
        }
        int ans=0;
        vis.assign(n+1,0);
        for(int i=0; i<n; ++i){
                if(!vis[i]){
                        c=ful[i], dfs(i,-1);
                        ans+=c*(c-1)/2;
                }
        }
        ans+=f;
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
