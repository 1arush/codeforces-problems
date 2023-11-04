#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int l,r,x,y;
  cin>>l>>r>>x>>y;
  if(x>r || y%x){
    cout<<0<<'\n'; return 0;
  }
  // find a,b in [l,r] such that gcd(a,b)=x, ab=xy
  // xy = (p1,k1)(p2,k2)..
  // distribute the gcd into (a,b)
  // the rest of the primes describe the count
  y/=x;
  vector<int> divs;
  for(int i=1; i*i<=y; i++){
    if(y%i==0){
      divs.push_back(i);
      if(i*i!=y) divs.push_back(y/i);
    }
  }
  int res=0;
  for(int p:divs){
    int q=y/p;
    if(p<=r/x && p>=(l+x-1)/x && q<=r/x && q>=(l+x-1)/x && __gcd(p,q)==1) res++;
  }
  cout<<res<<'\n';
  return 0;
}
