#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isP(ll n){
    if(n<2) return 0;
    else if(n==2) return 1;
    ll end=sqrt(n);
    if(n%2==0) return 0;
    for(int j=3;j<=end;j+=2){
        if(n%j==0) return 0;
    }
    return 1;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll num; cin>>num;
        ll sqr=sqrt(num);
        if(sqr*sqr==num and isP(sqr)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}