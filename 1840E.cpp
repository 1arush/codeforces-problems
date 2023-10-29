#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define int long long

const int M=1e9+9, p=31;

signed main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    string s,t;
    cin>>s>>t;
    int N=s.size();
    vector<int> p_pow(N);
    p_pow[0]=1;
    int s1=s[0]-'a'+1, s2=t[0]-'a'+1;
    for(int i=1; i<N; i++){
      p_pow[i]=(p_pow[i-1]*p)%M;
      s1=(s1+p_pow[i]*(s[i]-'a'+1))%M, s2=(s2+p_pow[i]*(t[i]-'a'+1))%M;
    }
    queue<int> id, u_time;
    int tq,q;
    cin>>tq>>q;
    int cur=1;
    auto add=[&](int &S, int ii, char ss){
      S=(S+p_pow[ii]*(ss-'a'+1)%M+M)%M;
    };
    auto rem=[&](int &S, int ii, char ss){
      S=(S-p_pow[ii]*(ss-'a'+1)%M+M)%M;
    };
    while(q--){
      int ty;
      cin>>ty;
      if(!u_time.empty() && u_time.front()==cur){
        int y=id.front();
        u_time.pop(), id.pop();
        add(s1,y,s[y]), add(s2,y,t[y]);
      }
      // queries
      if(ty==1){
        int pos;
        cin>>pos;
        --pos;
        // block pos
        // remove from hashes
        id.push(pos), u_time.push(cur+tq);
        rem(s1,pos,s[pos]), rem(s2,pos,t[pos]);
      }
      else if(ty==2){
        int l1,p1,l2,p2;
        cin>>l1>>p1>>l2>>p2;
        p1--, p2--;
        // swap 2 elements
        // change hashes of both and physically swap
        char c1=(l1==1 ? s[p1] : t[p1]);
        char c2=(l2==1 ? s[p2] : t[p2]);
        if(l1==1 && l2==1){
          swap(s[p1],s[p2]);
          rem(s1,p1,c1); add(s1,p1,c2);
          rem(s1,p2,c2); add(s1,p2,c1);
        }
        if(l1==1 && l2==2){
          swap(s[p1],t[p2]);
          rem(s1,p1,c1); add(s1,p1,c2);
          rem(s2,p2,c2); add(s2,p2,c1);
        }
        if(l1==2 && l2==1){
          swap(t[p1],s[p2]);
          rem(s2,p1,c1); add(s2,p1,c2);
          rem(s1,p2,c2); add(s1,p2,c1);
        }
        if(l1==2 && l2==2){
          swap(t[p1],t[p2]);
          rem(s2,p1,c1); add(s2,p1,c2);
          rem(s2,p2,c2); add(s2,p2,c1);
        }
      }
      else{
        cout<<(s1%M==s2%M ? "YES\n" : "NO\n");
        // compare if they are equal
      }
      cur++;
    }
  }
  return 0;
}
