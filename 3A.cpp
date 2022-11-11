#include <bits/stdc++.h>
using namespace std;
#define fora(i,a) for(int i=0;i<a;i++)
int main(){
    string st,en; cin>>st>>en;
    int r=en[0]-st[0],u=en[1]-st[1];
    int a=min(abs(r),abs(u)),z=r,x=u;
    if(z>0)  z-=a; 
    else     z+=a;
    if(x>0)  x-=a;
    else     x+=a;
    cout<<a+max(abs(z),abs(x))<<'\n';
    if(r>0 and u>0)       fora(i,a) cout<<"RU\n";
    else if(r>0 and u<0)  fora(i,a) cout<<"RD\n";
    else if(r<0 and u>0)  fora(i,a) cout<<"LU\n";
    else                  fora(i,a) cout<<"LD\n";
    if(r>0)  r-=a;
    else     r+=a;
    if(u>0)  u-=a;
    else     u+=a;
    if(u>0) fora(i,u)        cout<<"U\n";
    else if(u<0) fora(i,-u)  cout<<"D\n";
    else if(r>0) fora(i,r)   cout<<"R\n";
    else fora(i,-r)          cout<<"L\n";
}