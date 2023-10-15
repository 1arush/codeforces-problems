#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  for(int p=1; p<=n; p*=3){
    int l=n/p;
    if(__builtin_popcount(l)==1 && n%p==0){
      cout<<"Yes\n";
      return 0;
    }
  }
  cout<<"No\n";
  return 0;
}
