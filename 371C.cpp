#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  cin>>s;
  vector<int> n(3), p(3), cnt(3);
  for(int i=0; i<3; i++) cin>>n[i];
  for(int i=0; i<3; i++) cin>>p[i];
  int fin;
  cin>>fin;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='B') cnt[0]++;
    else if(s[i]=='S') cnt[1]++;
    else cnt[2]++;
  }
  int l=0, r=1e13;
  auto possible=[&](int x){
    int cost=0;
    for(int i=0; i<3; i++){
      cost+=max(x*cnt[i]-n[i],0LL)*p[i];
    }
    return cost<=fin;
  };
  while(r>l+1){
    int mid=(l+r)/2;
    if(possible(mid)) l=mid;
    else r=mid;
  }
  cout<<l<<'\n';
  return 0;
}
