#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vpii vector<pair<ll,ll>>
#define se second
int main(){
    ll n,f; cin>>n>>f;
    vpii v,u;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        v.push_back(make_pair(x,y));
        ll t=min(2*x,y);
        u.push_back(make_pair(t-min(x,y),i));
    }
    sort(u.rbegin(),u.rend());
    ll sum=0; int i=1;
    for(auto P:u){
        if(i<=f){
            sum+=min(2*v[P.se].first,v[P.se].se);
            i++;
        }
        else sum+=min(v[P.se].first,v[P.se].se);
    }
    cout<<sum;
}