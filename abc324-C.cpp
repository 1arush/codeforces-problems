#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  string t;
  cin>>n>>t;
  vector<int> id;
  for(int i=0; i<n; i++){
    string s;
    cin>>s;
    if(s.size()==t.size()){
      if(s==t) id.push_back(i);
      else{
        int diff=0;
        for(int j=0; j<s.size(); j++) diff+=(s[j]!=t[j]);
        if(diff==1) id.push_back(i);
      }
    }
    if(s.size()==t.size()+1){
      int l=0;
      while(l<t.size() && s[l]==t[l]) l++;
      string tp="", bp="";
      for(l; l<t.size(); l++){
        bp+=t[l]; tp+=s[l+1];
      }
      if(tp==bp) id.push_back(i);
    }
    if(s.size()+1==t.size()){
      int l=0;
      while(l<t.size() && s[l]==t[l]) l++;
      string tp="", bp="";
      for(l; l<s.size(); l++){
        bp+=s[l]; tp+=t[l+1];
      }
      if(tp==bp) id.push_back(i);
    }
  }
  cout<<id.size()<<'\n';
  for(int x:id) cout<<x+1<<' ';
  return 0;
}
