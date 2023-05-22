#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sub(map<ll,ll> & mp, ll & res){
    for(pair<ll,ll> p:mp){ 
        if(p.second>=2){ 
            res-=p.second*(p.second-1)/2; 
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int ttc=1;
    cin>>ttc;
    while(ttc--){
        ll n; cin>>n;
        vector<string> v(n);
        for(ll i=0; i<n; i++) cin>>v[i];
        ll res=0;
        for(ll j=0; j<=('k'-'a'); j++){
            map<ll,ll> mp;
            ll N=0;
            for(ll i=0; i<n; i++){
                if(v[i][0]==char('a'+j)){
                    ll y=v[i][1]-'a';
                    mp[y]++; N++;
                }
            }
            res+=N*(N-1)/2;
            sub(mp,res);
            mp.clear(); N=0;
            for(ll i=0; i<n; i++){
                if(v[i][1]==char('a'+j)){
                    ll y=v[i][0]-'a';
                    mp[y]++; N++;
                }
            }
            res+=N*(N-1)/2;
            sub(mp,res);
        }
        cout<<res<<"\n";
    }
}