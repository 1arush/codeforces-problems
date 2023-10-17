#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int k;
  cin>>k;
  // length 10
  vector<char> str {'c','o','d','e','f','o','r','c','e','s'};
  set<char> ss(str.begin(),str.end());
  if(k==1){
    cout<<"codeforces\n";
    return 0;
  }
  int i=1;
  auto F=[&](int i){
    int cmp=1;
    for(int j=0; j<10; j++) cmp*=i;
    return cmp;
  };
  while(F(i)<k) i++;
  i--;
  vector<int> x(10,i);
  int v=F(i);
  for(int j=0; j<10; j++){
    if(v>=k) break;
    v=(v/i)*(i+1);
    x[j]=i+1;
  }
  string res="";
  for(int i=0; i<10; i++){
    res+=string((int)x[i],str[i]);
  }
  cout<<res<<'\n';
  return 0;
}
