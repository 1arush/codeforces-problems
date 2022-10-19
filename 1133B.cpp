#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ll n,k; cin>>n>>k;
    map<int,int>mp;
    for(ll i=0;i<n;i++){
        ll x; cin>>x;
        mp[x%k]++;
    }
    ll gifts=mp[0]/2; mp[0]=0;
    if(k%2==0){
        gifts+=mp[k/2]/2; mp[k/2]=0;
    }
    for(auto p:mp){
        if(p.first>k/2) break;
        gifts+=(min(mp[p.first],mp[k-p.first]));
    }
    cout<<2*gifts;
}