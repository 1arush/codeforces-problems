#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  string t;
  cin>>n>>t;
  int m=t.size();
  vector<string> ss(n);
  vector<int> ff(n), cntb(m+4);
  for(int k=0; k<n; k++){
    string s;
    cin>>s;
    ss[k]=s;
    int fw=0, bw=0, j=0;
    for(int i=0; i<(int)s.size() && j<m; i++){
      if(s[i]==t[j]) j++;
    }
    ff[k]=j;
    j=m-1;
    for(int i=(int)s.size()-1; i>=0 && j>=0; i--){
      if(s[i]==t[j]) j--;
    }
    bw=m-j-1;
    cntb[bw]++;
  }
  vector<int> sfb(m+4);
  sfb[m]=cntb[m];
  for(int i=m-1; i>=0; i--){
    sfb[i]=sfb[i+1]+cntb[i];
  }
  int res=0;
  for(int i=0; i<n; i++){
    int x=ff[i];
    // x+y>=m -> y>=m-x
    res+=sfb[m-x];
  }
  cout<<res<<'\n';
  return 0;
}
