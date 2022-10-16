#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
void solve(){
    ll a,b; cin>>a>>b;
    if((a-b)!=1){
        cout<<"NO\n"; return;
    }
    for(ll i=2;i<=int(sqrt(a+b));i++){
        if((a+b)%i==0){
            cout<<"NO\n"; return;
        }
    }
    cout<<"YES\n";
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}