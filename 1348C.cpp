#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n,k;
    string s;
    cin>>n>>k>>s;
    sort(s.begin(),s.end());
    set<char> fs;
    for(int i=0; i<k; i++) fs.insert(s[i]);
    if(fs.size()>1){
      cout<<*prev(fs.end())<<'\n';
      continue;
    }
    fs.clear();
    for(int i=k; i<n; i++) fs.insert(s[i]);
    if(fs.size()==1){
      cout<<s[0]+string((n-1)/k,s[k])<<'\n';
      continue;
    }
    string res=s[0]+s.substr(k,n-k);
    cout<<res<<'\n';
  }
  return 0;
}
