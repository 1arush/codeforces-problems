#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
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
    int n,t; cin>>n>>t;
    vector<int>p;
    p.pb(0);
    for1(i,n){
        int y; cin>>y;
        p.pb(y+p[i-1]);
    }
    p.pb(INT32_MAX);
    int res=0;
    forn(i,n+1){
        // maximize 'l' such that a[l]-a[mid] <= t
        int l=i; // a[l] <= t
        int r=n+1; // a[r] > t
        while(r>l+1){
            int mid=(l+r)/2;
            if(p[mid]-p[i]<=t) l=mid;
            else r=mid;
        }
        res=max(l-i,res);
    }
    cout<<res<<"\n";
}