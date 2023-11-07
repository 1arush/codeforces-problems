#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

const int MOD=1e9+7;

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int l,r;
  cin>>l>>r;
  // sequence length 1,2,4,8,16,..
  // sequence parity o,e,o,e,o,...
  vector<int> v(1,1), pf(1,1);
  while((v.back()<<1)<=1e18){
    v.push_back(v.back()<<1);
    pf.push_back(pf.back()+v.back());
  }
  auto prefix=[&](int X){
    int id=lower_bound(pf.begin(),pf.end(),X)-pf.begin();
    int osum=0, esum=0;
    char parity=(id%2 ? 'e' : 'o');
    for(int i=0; i<id; i++){
      if(i%2) esum+=v[i];
      else osum+=v[i];
      esum%=MOD, osum%=MOD;
    }
    int d=X-(id ? pf[id-1] : 0);
    if(parity=='o') osum+=d;
    else esum+=d;
    esum%=MOD, osum%=MOD;
    int total=(MOD+esum*(esum+1)%MOD+osum*osum%MOD)%MOD;
    return total;
  };
  int max=prefix(r);
  int min=prefix(l-1);
  cout<<(MOD+max-min)%MOD;
  return 0;
}
