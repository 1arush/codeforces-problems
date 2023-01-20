#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(res) { cout<<res<<'\n'; return 0; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n,m,v; cin>>n>>m>>v;
    if(m>(n-1)*(n-2)/2+1 || m<n-1) print(-1)
    for1(i,n){
        if(m<=0) break;
        if(i==v) continue;
        cout<<i<<' '<<v<<"\n";
        m--;
    }
    int sp=(v==1) ? 3 : 1;
    for1(i,n){
        if(m<=0) break;
        if(i==sp || i==v) continue;
        for(int j=i+1;j<=n;j++){
            if(m<=0) break;
            if(j==sp || j==v) continue;
            cout<<i<<' '<<j<<"\n";
            m--;
        }
    }
}