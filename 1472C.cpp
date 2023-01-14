#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (ll i = 1; i <= ll(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(res) { cout<<res<<'\n'; continue; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll>v(n+1),dp(n+1);
        for1(i,n) cin>>v[i];
        forn(i,n+1) dp[i]=v[i];
        dp[1]=v[1];
        for1(i,n){
            if(i+v[i]<=n) dp[i+v[i]]=max(dp[i+v[i]],dp[i]+v[i+v[i]]);
        }
        ll res=0;
        for(auto x:dp) res=max(res,x);
        print(res)
    }
}