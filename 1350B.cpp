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
    vector<int> a(n+1), dp(n+1,1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++){
      for(int j=i; j<=n; j+=i){
        if(a[j]>a[i]) dp[j]=max(dp[j],dp[i]+1);
      }
    }
    int res=*max_element(dp.begin(),dp.end());
    cout<<res<<'\n';
  }
  return 0;
}
