#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod=1e9+7;

vector<vector<int>> gr;
vector<int> dpw, dpb;

void dfs(int u, int p){
        dpw[u]=dpb[u]=1;
        for(int v:gr[u]){
                if(v==p) continue;
                dfs(v,u);
                dpw[u]*=(dpw[v]+dpb[v])%mod;
                dpb[u]*=dpw[v];
                dpw[u]%=mod, dpb[u]%=mod;
        }
}

void solve_test(){
        int n;
        cin>>n;
        gr=vector<vector<int>> (n);
        dpw=vector<int> (n);
        dpb=vector<int> (n);
        for(int i=1; i<n; ++i){
                int u, v;
                cin>>u>>v, --u, --v;
                gr[u].push_back(v);
                gr[v].push_back(u);
        }
        // what the heck, let's root at 0
        dfs(0,-1);
        cout<<(dpw[0]+dpb[0])%mod<<'\n';
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
