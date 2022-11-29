#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define print(x,y) { cout<<x<<' '<<y<<'\n'; continue; }
vector<ll> factors(ll n){
    vector<ll> f;
    for(ll x=2;x*x<=n;x++){
        while(n%x==0){
            f.push_back(x); n/=x;
        }
    } if(n>1) f.push_back(n);
    return f;
}
int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        if(n%2==0) print(n/2,n/2)
        vector<ll>f=factors(n);
        if(f.size()==1) print(1,n-1)
        else{
            ll ans=1; f[0]=1;
            for(int i=0;i<f.size();i++) ans*=f[i];
            print(ans,n-ans)
        }
    }
}