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
    stack<pair<bool,bool>> stp;
    bool ok=true;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
      if(s[i]=='+'){
        if(stp.empty()){
          stp.emplace(1,0), cnt++;
        }
        else{
          if(stp.top().first==0){
            stp.emplace(0,1);
          }
          else{
            stp.emplace(1,0), cnt++;
          }
        }
      }
      else if(s[i]=='-'){
        if(stp.top().first==1){
          cnt--;
          if(stp.top().second==1){
            stp.pop();
            // each element edited at most once
            int z=0;
            while(!stp.empty() && stp.top().second==0){
              stp.pop(), z++;
            }
            while(z--){
              stp.emplace(1,1);
            }
          }
          else stp.pop();
        }
        else stp.pop();
      }
      else if(s[i]=='0'){
        if(stp.size()<=1){
          ok=false; break;
        }
        else{
          if(stp.top().first==1 && stp.top().second==0){
            cnt--;
            stp.pop();
            stp.emplace(0,1);
            continue;
          }
          else if(stp.top().first==1 && stp.top().second==1){
            ok=false; break;
          }
        }
      }
      else{
        if(stp.size()<=1){
          continue;
        }
        if(cnt==stp.size()){
          stp.pop();
          int z=0;
          while(!stp.empty() && stp.top().second==0){
            z++, stp.pop();
          }
          while(z--){
            stp.emplace(1,1);
          }
          stp.emplace(1,1);
          continue;
        }
        ok=false; break;
      }
      // cerr<<i<<' '<<cnt<<' '<<stp.size()<<'\n';
    }
    cout<<(ok ? "YES\n" : "NO\n");
  }
  return 0;
}
