#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n;
    cin>>n;
    vector<int> a(n+1), dp(n+4);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=n; i>0; i--){
      if(i+a[i]<=n){
        dp[i]=max(dp[i],a[i]+1+dp[i+a[i]+1]);
      }
      dp[i]=max(dp[i],dp[i+1]);
    }
    int res=n-dp[1];
    cout<<res<<'\n';    
  }
  return 0;
}
