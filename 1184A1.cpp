#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool solve(ll n){
    if(n==0) return 0;
    for(ll x=1;x<=int(sqrt(n))+1;x++){
        if(n%x==0){
            if((n/x-1-x)%2==0){
                if(n/x-1-x==0) return 0;
                cout<<x<<' '<<(n/x-1-x)/2;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    ll n; cin>>n;
    string s=(solve(n-1))?"\n":"NO";
    cout<<s;
}