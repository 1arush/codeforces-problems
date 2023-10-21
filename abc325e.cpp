#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<vector<int>> D(n+4,vector<int>(n+4,1e14));
  vector<int> fd(n+1,1e14), bd(n+4,1e14);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++) cin>>D[i][j];
  }
  // dijk
  vector<bool> seen(n+4,false);
  fd[1]=0;
  for(int i=1; i<=n; i++){
    int v=-1;
    for(int j=1; j<=n; j++){
      if(!seen[j] && (v==-1 || fd[j]<fd[v])) v=j;
    }
    if(fd[v]==1e14) break;
    seen[v]=true;
    for(int j=1; j<=n; j++){
      if(fd[v]+D[v][j]*a < fd[j]){
        fd[j]=fd[v]+D[v][j]*a;
      }
    }
  }
  // reverse dijk
  seen.assign(n+4,false);
  bd[n]=0;
  for(int i=1; i<=n; i++){
    int v=-1;
    for(int j=1; j<=n; j++){
      if(!seen[j] && (v==-1 || bd[j]<bd[v])) v=j;
    }
    if(bd[v]==1e14) break;
    seen[v]=true;
    for(int j=1; j<=n; j++){
      if(bd[v]+D[v][j]*b+c < bd[j]){
        bd[j]=bd[v]+D[v][j]*b+c;
      }
    }
  }
  int res=1e18;
  res=min({res,D[1][n]*a,D[1][n]*b+c});
  for(int i=1; i<=n; i++){
    int cost=fd[i]+bd[i];
    res=min(res,cost);
  }
  cout<<res<<'\n';
  return 0;
}
