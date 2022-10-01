#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n,x; cin>>n>>x;
    ll Y=0;
    if(x>n*n) cout<<0;
    else{
        for(ll i=1;i<=n;i++){
            if(x%i==0 && x/i<=n) Y++;
        }
        cout<<Y;
    }
}