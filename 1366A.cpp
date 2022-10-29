#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b; cin>>a>>b;
    if(b>=2*a){
        cout<<a<<'\n'; return;
    }
    if(a>=2*b){
        cout<<b<<'\n'; return;
    }
    cout<<(a+b)/3<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}