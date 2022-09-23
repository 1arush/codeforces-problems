#include <iostream>
using namespace std;
int main(){
    int x,y,z; cin>>x>>y>>z;
    int a,b,c; cin>>a>>b>>c;
    x-=a; y-=b; z-=c;
    if(abs(x)+abs(y)+abs(z)==3) cout<<"NO";
    else cout<<"YES";
}