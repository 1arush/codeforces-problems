#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int q,x;
  cin>>q>>x;
  vector<int> cnt(x);
  set<pair<int,int>> pq;
  for(int i=0; i<x; i++) pq.emplace(0,i);
  while(q--){
    int y;
    cin>>y;
    y%=x;
    pq.erase({cnt[y],y});
    cnt[y]++;
    pq.insert({cnt[y],y});
    // what is the mex? 
    // m := cnt[v], such that cnt[v] is minimal, break ties with smaller v
    // mex is v+(m+1)*x
    auto f=*pq.begin();
    int res=f.second+x*f.first;
    cout<<res<<'\n';
  }
  return 0;
}
