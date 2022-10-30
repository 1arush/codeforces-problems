#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,m; cin>>n;
    int a[100005];
    for(ll i=1;i<=n;i++){
        int x; cin>>x;
        a[x]=i;
    }
    cin>>m;
    ll l=0,r=0;
    for(ll i=1;i<=m;i++){
        int y; cin>>y;
        l+=a[y];
        r+=n+1-a[y];
    }
    cout<<l<<' '<<r;
}