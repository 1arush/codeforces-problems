#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin>>n;
  vector<int> a(n);
  map<int,int> mp;
  for(int i=0; i<n; i++){
    cin>>a[i];
    mp[a[i]]++;
  }
  cout<<(mp.size()==1 ? "Yes\n" : "No\n");
  return 0;
}
