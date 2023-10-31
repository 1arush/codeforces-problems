#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

const int MOD=1e9+7;

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n,k;
    cin>>n>>k;
    // (very interesting problem)
    int dp[n+2][k+1][2];
    for(int i=0; i<n+2; i++){
      for(int j=0; j<k+1; j++) dp[i][j][0]=dp[i][j][1]=0LL;
    }
    // dp[i][j][k] = number of elements added if j collides at plane i in direction k
    // k: <- 0
    for(int i=1; i<=k; i++) dp[0][i][0]=dp[n+1][i][1]=1LL; // borders
    for(int i=0; i<n+2; i++) dp[i][1][0]=dp[i][1][1]=1LL;  // 1 passes through everything
    for(int j=2; j<=k; j++){
      vector<int> sfsum(n+2,0LL);
      for(int i=n; i>=0; i--){
        sfsum[i]=(sfsum[i+1]+dp[i][j-1][0])%MOD;
      }
      for(int i=1; i<=n; i++){
        dp[i][j][0]=(dp[i-1][j][0]+dp[i+1][j-1][1])%MOD;
        dp[i][j][1]=(1LL+(sfsum[i-1]-sfsum[n])+MOD)%MOD;
      } 
      // cout<<'\n';
    }
    int res=dp[1][k][1];
    cout<<res<<'\n';
  }
  return 0;
}
