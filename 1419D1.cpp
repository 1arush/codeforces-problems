#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n; cin>>n;
    vector<ll>a(n),se(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        if(i<n/2)
            se[2*i+1]=a[i];
        else
            se[2*(i-n/2)]=a[i];
    } 
    if(n%2==0) cout<<n/2-1<<'\n';
    else cout<<n/2<<'\n';
    for(ll i=0;i<n;i++) cout<<se[i]<<' ';
}