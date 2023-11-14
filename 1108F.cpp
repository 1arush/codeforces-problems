#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

map<int,vector<pair<int,int>>> mp;

struct DSU {
  // generalized in the struct form
  vector<int> sz, parent;
  DSU(int n){
    sz.assign(n,1), parent.resize(n);
    iota(parent.begin(),parent.end(),0);
  }
  ~DSU(){
    sz.clear(); parent.clear();
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

  int n,m;
  cin>>n>>m;
  DSU ds(n+1);
  vector<vector<int>> eg;
  for(int i=0; i<m; i++){
    int fr,to,we;
    cin>>fr>>to>>we;
    eg.emplace_back(vector<int>({we,fr,to}));
  }
  sort(eg.begin(),eg.end());
  int res=0, i=0;
  while(i<m){
    int j=i, len=0;
    while(j<m && eg[j][0]==eg[i][0]){
      j++;
    }
    len+=j-i;
    for(int k=i; k<j; k++){
      if(ds.leader(eg[k][1])==ds.leader(eg[k][2])){
        len--;
      }
    }
    for(int k=i; k<j; k++){
      if(ds.leader(eg[k][1])!=ds.leader(eg[k][2])){
        ds.unite(eg[k][1],eg[k][2]);
        len--;
      }
    }
    res+=len;
    i=j;
  }
  cout<<res<<'\n';
  return 0;
}
