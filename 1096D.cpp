#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int int64_t

const int MAX=1e17;

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  string s;
  cin>>n>>s;
  vector<int> a(n);
  for(int &i:a) cin>>i;
  string h="hard";
  vector<vector<int>> dp(n,vector<int>(4,MAX));
  // dp[0]=min cost to destroy h
  // dp[1]=min cost to destroy ha
  // dp[2]=min cost to destroy har .. 
  dp[0][0]=(s[0]=='h' ? a[0] : 0);
  dp[0][1]=dp[0][2]=dp[0][3]=0;
  for(int i=1; i<n; i++){
    dp[i][0]=dp[i-1][0]+(s[i]=='h' ? a[i] : 0);
    for(int j=1; j<4; j++){
      if(s[i]==h[j]){
        dp[i][j]=min(dp[i-1][j]+a[i],dp[i-1][j-1]);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  // for(int j=0; j<4; j++){
  //   for(int i=0; i<n; i++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  cout<<dp[n-1][3]<<'\n';
  return 0;
}
