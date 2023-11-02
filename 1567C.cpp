#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n, d;
    cin>>n, d=n;
    vector<int> num;
    while(n){
      num.push_back(n%10);
      n/=10;
    }
    int od=0, ev=0;
    reverse(num.begin(),num.end());
    for(int i=num.size()-1; i>=0; i--){
      int d=num.size()-1-i;
      if(d%2==0) od=(od*10+num[d]);
      else ev=(ev*10+num[d]);
    }
    if(od==0 || ev==0){
      cout<<max(od,ev)-1<<'\n';
      continue;
    }
    int res=(ev+1)*(od+1)-2;
    cout<<res<<'\n';
  }
  return 0;
}
