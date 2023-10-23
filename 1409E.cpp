#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n,k,d;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>d;
    sort(a.begin(),a.end());
    // for(int i=1; i<=n; i++) cout<<a[i]<<' '; cout<<'\n';
    vector<int> dp(n+1);
    dp[n]=1;
    for(int i=n-1; i; i--){
      dp[i]=dp[i+1];
      int idx=upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
      dp[i]=max(dp[i],idx-i);
    }
    int res=0;
    for(int l=1; l<=n; l++){
      // place left border on l
      int idx=upper_bound(a.begin(),a.end(),a[l]+k)-a.begin();
      int cnt=idx-l;
      if(idx<=n) cnt+=dp[idx];
      res=max(res,cnt);
    }
    cout<<res<<'\n';
  }
  return 0;
}
