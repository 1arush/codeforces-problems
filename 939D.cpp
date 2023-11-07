#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

struct DSU {
  // generalized in the struct form
  vector<int> sz, parent;
  DSU(int n){
    sz.assign(n,1), parent.resize(n);
    iota(parent.begin(),parent.end(),0);
  }
  int leader(int a){
    if(a==parent[a]) return a;
    return parent[a]=leader(parent[a]);
  }
  void unite(int a, int b){
    a=leader(a), b=leader(b);
    if(sz[a]<sz[b]) swap(a,b);
    if(a!=b){
      parent[b]=a, sz[a]+=sz[b];
    }
  }
};

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  DSU dsu(26);
  string s,t;
  cin>>s>>t;
  for(int i=0; i<n; i++) dsu.unite(s[i]-'a',t[i]-'a');
  vector<pair<int,int>> vp;
  for(int a=0; a<26; a++){
    if(a==dsu.leader(a)) continue;
    vp.emplace_back(a,dsu.leader(a));
  }
  cout<<vp.size()<<'\n';
  for(auto pp:vp) cout<<char(pp.first+'a')<<' '<<char(pp.second+'a')<<'\n';  
  return 0;
}
