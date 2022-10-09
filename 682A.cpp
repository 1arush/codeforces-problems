#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// calculate end for each i
int main(){
    ll n,m; cin>>n>>m;
    ll count=0;
    for(ll i=1;i<=n;i++){
        ll j=5-i%5,end;
        if(m%5==0){
            if(i%5==0) end=m;
            else end=m-i%5;
        }
        else{
            if(i%5==0) end=5*(m/5);
            else{
                end=5*(m/5)+j;
                if(end>m) end-=5;
            }
        }
        count+=(end-j)/5+1;
    }
    cout<<count;    
}