#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll F(ll N){
    return (3*N*N+N)/2;
}
// sequence is {2,7,15,26,40....}
ll maxH(ll n){
    ll i=1;
    while(F(i)<=n) i++;
    return F(i-1);
}
int main(){
    ll n; cin>>n;
    while(n--){
        ll x; cin>>x;   
        ll ct=0;
        while(x>=2){
            x-=maxH(x); ct++;
        }
        cout<<ct<<'\n';
    }
}