#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void solve(){
    long long x; cin>>x;
    long long a=1;
    while(a<=int(cbrt(x))){
        int cb=int(cbrt(x-a*a*a));
        if(cb==0){
            cout<<"no\n"; return;
        }
        if(cbrt(x-a*a*a)==cb){
            cout<<"yes\n"; return;
        }
        else a++;
    }
    cout<<"no\n";
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}