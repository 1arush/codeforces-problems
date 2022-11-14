#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x; return 0; }
int main(){
    int a,x,y; cin>>a>>x>>y;
    if(x>=a or x<=-a) print(-1)
    if(y<=0 or y%a==0) print(-1)
    if(y<a){
        if(2*x<=-a or 2*x>=a) print(-1)
        print(1)
    } y-=a;
    if((y/a)%2==0){
        if(2*x<=-a or 2*x>=a) print(-1)
        print(2+3*(y/(2*a)));
    }
    else if(x>0) print(2+3*(y/(2*a))+2)
    else if(x<0) print(2+3*(y/(2*a))+1)
    else print(-1)
}