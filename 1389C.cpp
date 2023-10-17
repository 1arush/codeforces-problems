#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    string s;
    cin>>s;
    int n=s.size();
    map<int,int> mp;
    for(char ch:s){
      mp[ch-'0']++;
    }
    int res=0;
    for(auto pp:mp){
      res=max(res,pp.second);
    }
    for(int i=0; i<=9; i++){
      for(int j=0; j<=9; j++){
        // sequence of form ABABABAB
        char A='0'+i, B='0'+j, prev;
        int len=0; 
        prev=B;
        for(int k=0; k<n; k++){
          if(prev==B && s[k]==A){
            prev=A, len++;
          }
          else if(prev==A && s[k]==B){
            prev=B, len++;
          }
        }
        res=max(res,len-len%2);
        // cerr<<A<<' '<<B<<" : "<<len<<'\n';
      }
    }
    cout<<n-res<<'\n';
  }
  return 0;
}
