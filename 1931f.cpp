#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin>>_;
    while(_--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> gr(n);
        for(int i=0; i<k; ++i){
            int prev=0;
            for(int j=0; j<n; ++j){
                int x;
                cin>>x, --x;
                if(j>1){
                    gr[prev].push_back(x);
                }
                prev=x;
            }
        }
        vector<int> col(n);
        bool f=0;
        auto dfs=[&](auto &&dfs, int u)-> void {
            col[u]=1;
            for(int v:gr[u]){
                if(col[v]==0 && !f){
                    dfs(dfs,v);
                }
                else if(col[v]==1 && !f){
                    f=1; break;
                }
            }
            col[u]=2;
        };
        for(int i=0; i<n; ++i){
            if(col[i]==0 && !f) dfs(dfs,i);
        }
        cout<<(f ? "NO" : "YES")<<'\n';
    }
    return 0;
}
