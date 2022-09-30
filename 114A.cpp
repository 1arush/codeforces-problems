#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ll k,l; cin>>k>>l;
    ll power=1,count=0;
    while(power<l){
        power*=k; count++;
    }
    if(power==l) cout<<"YES\n"<<count-1;
    else cout<<"NO\n";
}