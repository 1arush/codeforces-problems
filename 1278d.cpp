#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> gr;
vector<int> use;
bool ok=1;

void dfs(int u, int p){
        use[u]=1;
        for(int v:gr[u]){
                if(v==p) continue;
                if(use[v]) ok=0;
                else dfs(v,u);
        }
}

void solve_test(){
        int n;
        cin>>n;
        vector<int> c(2*n);
        for(int i=0; i<n; ++i){
                int l, r;
                cin>>l>>r, --l, --r;
                c[l]=c[r]=i;
        }              
        vector<int> loc(n,-1);  
        gr=vector<vector<int>> (n);
        use=vector<int> (n);
        set<pair<int,int>> s;
        int tot=0;
        for(int i=0; i<2*n; ++i){
                if(loc[c[i]]<0){
                        // left border
                        s.emplace(i,c[i]);
                        loc[c[i]]=i;
                }else{
                        s.erase({loc[c[i]],c[i]});
                        auto it=s.upper_bound({loc[c[i]],-1});
                        while(it!=s.end() && it->first<i){
                                tot++;
                                gr[it->second].push_back(c[i]);
                                gr[c[i]].push_back(it->second);
                                if(tot>n-1){
                                        cout<<"NO\n"; return;
                                }
                                it=next(it);
                        }
                }
        }
        if(tot!=n-1){
                cout<<"NO\n"; return;
        }
        dfs(0,-1);
        for(int i=0; i<n; ++i){
                if(!use[i] || !ok){
                        cout<<"NO\n"; return;
                }
        }
        cout<<"YES\n";
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
