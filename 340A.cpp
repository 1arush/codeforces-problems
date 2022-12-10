#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return 0; }
int main(){
    int x,y,a,b; cin>>x>>y>>a>>b;
    int d=(x*y)/__gcd(x,y);
    if(a%d!=0) a=(a-a%d+d);
    if(b%d!=0) b=(b-b%d);
    if(b<a) print(0)
    cout<<(b-a)/d+1;
}