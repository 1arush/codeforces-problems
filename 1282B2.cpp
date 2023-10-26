#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n,p,k;
    cin>>n>>p>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    // for(int x:a) cout<<x<<' '; cout<<'\n';
    vector<int> pf(n,a[0]);
    for(int i=1; i<n; i++) pf[i]=pf[i-1]+a[i];
    // there is at least element from the first k
    int res=0;
    for(int i=0; i+1<k; i++){
      int cnt=0, cur=p;
      for(int j=i; j<n; j+=k){
        if(a[j]>cur) break;
        cur-=a[j];
        cnt+=(j==i ? 1 : k);
      }
      int nxt=upper_bound(pf.begin(),pf.end(),cur)-pf.begin();
      cnt+=max(0,min(nxt,i));
      // cerr<<i<<'-'<<nxt<<' '<<cnt<<'\n';
      res=max(res,cnt);
    }
    int cnt=0, cur=p;
    for(int j=k-1; j<n; j+=k){
      if(a[j]>cur) break;
      cur-=a[j], cnt+=k;
    }
    res=max(res,cnt);
    cout<<res<<'\n';
  }
  return 0;
}
