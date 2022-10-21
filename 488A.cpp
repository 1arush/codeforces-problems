#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isLucky(ll n){
    n=abs(n);
    while(n>0){
        if(n%10==8) return 1;
        n/=10;
    }
    return 0;
}
int main(){
    ll n; cin>>n;
    ll b=n;
    if(n>=0){
        if(isLucky(n)) n++;
        while(!isLucky(n)) n++;
        goto p;
    }
    else{
        n*=-1;
        if(isLucky(n)) n--;
        while(!isLucky(n)) n--; n*=-1;
        goto p;
    }
p:  cout<<n-b; return 0;
}