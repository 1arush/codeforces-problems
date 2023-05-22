#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int ttc=1;
    cin>>ttc;
    while(ttc--){
        ll n,k; cin>>n>>k;
        vector<ll> s(k);
        for(int i=0; i<k; i++){
            cin>>s[i];
        }
        if(k==1){
            cout<<"Yes\n"; continue;
        }
        bool ok=true;
        for(int x=k-1; x>0; x--){
            if(x+1<k){
                if(s[x+1]-s[x]<s[x]-s[x-1]){
                    ok=false; break;
                }
            }
        }
        ll d=s[1]-s[0];
        if(s[0]>(n-k+1)*d || !ok) cout<<"No\n";
        else cout<<"Yes\n";
    }
}