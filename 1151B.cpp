#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,m;
  cin>>n>>m;
  vector<vector<int>> A(n,vector<int>(m));
  for(auto &v:A){
    for(int &a:v) cin>>a;
  }
  for(int bit=0; bit<10; bit++){
    // bruteforce for each bit
    set<int> o, z, nxt;
    for(int i=0; i<n; i++){
      int cnt=0;
      for(int j=0; j<m; j++){
        cnt+=(A[i][j]&(1<<bit) ? 1 : 0);
      }
      if(cnt==m) o.insert(i);
      else if(cnt==0) z.insert(i);
      else nxt.insert(i);
    }
    vector<int> sz(n);
    if(o.size()%2==0){
      if(nxt.size()==0) continue;
      bool ok=false;
      for(int i=0; i<n; i++){
        if(o.count(i) || z.count(i)){
          sz[i]=1; continue;
        }
        int srch=(ok ? 0 : 1);
        for(int j=0; j<m; j++){
          int f=(A[i][j]&(1<<bit) ? 1 : 0);
          if(f==srch && srch==1){
            ok=true, sz[i]=j+1;
            break;
          }
          else if(f==srch){
            sz[i]=j+1; break;
          }
        }
      }
      cout<<"TAK\n";
      for(int x:sz) cout<<x<<' '; cout<<'\n';
      return 0;
    }
    for(int i=0; i<n; i++){
      if(o.count(i) || z.count(i)){
        sz[i]=1; continue;
      }
      for(int j=0; j<m; j++){
        int f=(A[i][j]&(1<<bit) ? 1 : 0);
        if(f==0){
          sz[i]=j+1; break;
        }
      }
    }
    cout<<"TAK\n";
    for(int x:sz) cout<<x<<' '; cout<<'\n';
    return 0;
  }
  cout<<"NIE\n";
  return 0;
}
