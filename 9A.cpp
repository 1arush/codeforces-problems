#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,w; cin>>y>>w;
    y=7-max(y,w);
    w=__gcd(y,6);
    if(6%y!=0) cout<<y/w<<"/"<<6/w;
    else cout<<"1/"<<6/y;
}