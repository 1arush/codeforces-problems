#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

vector<vector<int>> gr;
map<vector<int>,int> children;
vector<int> hsh;
vector<bool> mark;
int it=1;

void dfs(int i){
    mark[i]=true;
    vector<int> values;
    bool lf=true;
    for(int j:gr[i]){
        if(!mark[j]){
            dfs(j); lf=false;
            values.push_back(hsh[j]);
        }
    }
    if(lf){
        hsh[i]=0; return;
    }
    sort(values.begin(),values.end());
    if(children.count(values)==0){
        children[values]=it; ++it;
    }
    hsh[i]=children[values];
}

bool check(int i, int par){
    // debug(i);
    map<int,int> mp;
    for(int j:gr[i]){
        if(j!=par) mp[hsh[j]]++;
    }
    vector<int> ov, ev;
    for(auto p:mp){
        if(p.second&1) ov.push_back(p.first);
        else ev.push_back(p.first);
    }
    if(ov.size()>1) return false;
    if(ov.size()==0) return true;
    bool nxt=true;
    for(int j:gr[i]){
        if(mp[hsh[j]]&1 && j!=par){
            nxt&=check(j,i); break;
        }
    }
    return nxt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"YES\n"; continue;
        }
        gr.assign(n+1,{}); hsh.assign(n+1,-1); 
        mark.assign(n+1,false); children.clear(); it=1;
        for(int i=1; i<n; i++){
            int u,v;
            cin>>u>>v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1);
        // for(auto v:children){
        //     for(int m:v.first) cout<<m<<':'; cout<<'\n';
        //     cout<<v.second<<'\n';
        // }
        bool ok=check(1,-1);
        cout<<(ok ? "YES" : "NO");
        cout<<'\n';
        // for(int i=1; i<=n; i++) cout<<hsh[i]<<' '; cout<<'\n';
    }
    return 0;
}