#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void answer(){
    ll k,x; cin>>k>>x;
    for(ll i=1;i<k;i++) x+=9;
    cout<<x<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--) answer();
}