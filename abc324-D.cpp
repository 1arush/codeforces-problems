#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  vector<int> cnt(10,0);
  string s;
  for(int i=0; i<n; i++){
    char ch;
    cin>>ch;
    cnt[ch-'0']++, s+=ch;
  }
  sort(s.rbegin(),s.rend());
  int lim=stoll(s), res=0;
  if(lim==0){
    cout<<1<<'\n';
    return 0;
  }
  auto possible=[&](int i){
    vector<int> copy=cnt;
    assert(copy.size()==10);
    while(i){
      int r=i%10;
      i/=10;
      if(copy[r]==0 && r!=0) return false;
      copy[r]--;
    }
    for(int i=1; i<10; i++){
      if(copy[i]>0) return false;
    }
    return true;
  };
  for(int i=1; i*i<=lim; i++){
    if(possible(i*i)) res++;
  }
  cout<<res<<'\n';
  return 0;
}
