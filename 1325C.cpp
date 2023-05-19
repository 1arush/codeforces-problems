#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> g;
vector<bool> mark;
map<pair<int,int>,int> edg;
bool done=false;

void dfs(int u){
    mark[u]=true;
    if(g[u].size()>=3 && !done){
        int cnt=1, zer=0;
        for(int i:g[u]){
            if(cnt>=3 && zer>=1) break;
            if(!mark[i] && cnt<3){edg[{u,i}]=edg[{i,u}]=cnt; ++cnt;}
            else if(zer==0){edg[{u,i}]=edg[{i,u}]=0; ++zer;}
        }
        if(cnt==3){done=true;}
    }
    if(done) return;
    for(int v:g[u]){
        if(!mark[v]) dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int ttc=1;
    // cin>>ttc;
    while(ttc--){
        int n; cin>>n;
        mark.assign(n+1,false);
        vector<pair<int,int>> ord;
        for(int i=1; i<n; i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            edg[{u,v}]=-1;
            ord.push_back({u,v});
        }
        dfs(1);
        int ct=(done ? 3 : 0);
        for(int i=0; i<n-1; i++){
            if(edg[ord[i]]==-1){
                edg[ord[i]]=ct; ++ct;
            }
        }
        for(auto p:ord) cout<<edg[p]<<"\n";
    }
}