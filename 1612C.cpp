#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(res) { cout<<res<<'\n'; continue; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef unsigned long long ll;
typedef long double ld;

ll f(ll n, ll k){
    if(n<=k) return (n*(n+1))/2;
    if(n>2*k-1) return k*k;
    ll t=2*k-n-1;
    return k*k-(t*(t+1))/2;
}
int main(){
    ll t; cin>>t;
    while(t--){
        ll k,x; cin>>k>>x;
        if(k*k<=x) print(2*k-1)
        ll l=0; 
        ll r=INT_MAX; // a[r] >= x (minimize mid)
        while(r>l+1){
            ll mid=(l+r)/2;
            if(f(mid,k)>=x) r=mid;
            else l=mid;
        }
        print(r)
    }
}