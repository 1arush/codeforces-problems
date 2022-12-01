#include <bits/stdc++.h>
using namespace std;
#define p 1000000007
typedef long long ll;
ll powmod(ll x, ll y){
    ll a=1; x=x%p;
    while(y>0){
        if(y & 1) a=(a*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return a;
}
int main(){
    ll ans,temp,ret,n; cin>>n;
    ll n1=3,n2=7;
    ans=powmod(n1,3*n);
    temp=powmod(n2,n);
    ret=(ans-temp)%p;
    cout<<(ret%p+p)%p;
}