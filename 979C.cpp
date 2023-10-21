#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int n,x,y;
vector<vector<int>> gr;
vector<int> subtree;
vector<bool> contains;

void dfs(int i, int par){
  int X=1;
  for(int j:gr[i]){
    if(j==par) continue;
    dfs(j,i);
    X+=subtree[j];
    contains[i]=contains[i]||contains[j];
  }
  subtree[i]=X;
  if(i==y) contains[i]=true;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  cin>>n>>x>>y;
  gr.resize(n+1);
  subtree.resize(n+1);
  contains.resize(n+1);
  for(int i=1; i<n; i++){
    int u,v;
    cin>>u>>v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(x,-1);
  long long u_cnt=1, v_cnt=subtree[y];
  for(int j:gr[x]){
    if(contains[j]) continue;
    u_cnt+=subtree[j];
  }
  long long bad=u_cnt*v_cnt;
  // debug(bad);
  long long res=n;
  res=res*(res-1)-bad;
  cout<<res<<'\n';
  return 0;
}
