#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

const int MOD=998244353;

int binary_power(int x, int n, int m=MOD){
  int res=1;
  while(n>0){
    if(n&1) res=res*x%m;
    x=x*x%m; n>>=1;
  }
  return res;
}

int inverse(int x, int m=MOD){
  int res=binary_power(x,m-2,m);
  return res;
}


signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1; i<=n; i++) cin>>a[i];
  vector<int> dp(n+1), sf(n+1);
  int inv=inverse(n);
  // dp[i] denotes expected value if we are at i
  dp[n]=sf[n]=a[n];
  for(int i=n-1; i>=0; i--){
    // dp[i]=a[i]+sum over 1/(n-i)*(dp[j]) for j=i+1..n 
    dp[i]=a[i]+inv*sf[i+1]%MOD;
    sf[i]=sf[i+1]+dp[i]%MOD;
    sf[i]%=MOD, dp[i]%=MOD;
  }
  cout<<dp[0]<<'\n';
  return 0;
}
