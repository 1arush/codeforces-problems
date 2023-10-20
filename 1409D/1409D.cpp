#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    string s;
    int sum;
    cin>>s>>sum;
    s='0'+s;
    int res=1e18;
    auto get_sum=[&](int x){
      int ans=0;
      while(x){
        ans+=x%10;
        x/=10;
      }
      return ans;
    };
    int f_check=stoll(s);
    if(get_sum(f_check)<=sum){
      cout<<0<<'\n';
      continue;
    }
    for(int i=0; i<s.size(); i++){
      // prefix up to i is used
      int v=stoll(s.substr(0,i+1))+1;
      string right=string(s.size()-1-i,'0');
      int new_int=stoll(to_string(v)+right);
      // cerr<<to_string(v)+right<<'\n';
      if(get_sum(new_int)<=sum){
        res=min(res,new_int);
      }
    }   
    cout<<res-stoll(s)<<'\n';
  }
  return 0;
}
