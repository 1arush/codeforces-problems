#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  vector<int> a(n), b(n), c(n);
  for(int i=0; i<n; i++){
    cin>>a[i]>>b[i];
    c[i]=a[i]-b[i];
  }
  int B=accumulate(b.begin(),b.end(),0LL);
  int A=accumulate(a.begin(),a.end(),0LL);
  int res=n*B-A;
  sort(c.begin(),c.end());
  for(int i=0; i<n; i++){
    res+=c[i]*(n-i);
  }
  cout<<res<<'\n';
  return 0;
}
