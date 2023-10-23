#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n;
    cin>>n;
    vector<int> a(n), cnt(n,0);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=1; i<n; i++){
      // a[i-1]*pow(2,p) <= a[i]*pow(2,q)
      cnt[i]=cnt[i-1];
      int l=a[i-1], r=a[i];
      if(l>r){
        while(l>r){
          r<<=1;
          cnt[i]++;
        }
        continue;
      }
      int t=0;
      while(l*2LL<=r){
        t++, l<<=1;
      }
      cnt[i]=max(0LL,cnt[i]-t);
    }
    int res=accumulate(cnt.begin(),cnt.end(),0LL);
    cout<<res<<'\n';
  }
  return 0;
}
