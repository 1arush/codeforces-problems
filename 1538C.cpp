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
    int t; cin>>t;
    while(t--){
        int n,lp,rp; cin>>n>>lp>>rp;
        vector<int>a(n);
        forn(i,n) cin>>a[i];
        sort(all(a));
        ll res=0;
        forn(i,n-1){
            int l=i; // a[l] <= x
            int r=n; // a[r] > x
            while(r>l+1){
                int mid=(l+r)/2;
                if(a[i]+a[mid]<=lp-1) l=mid;
                else r=mid;
            }
            res-=l;
            l=i; r=n;
            while(r>l+1){
                int mid=(l+r)/2;
                if(a[i]+a[mid]<=rp) l=mid;
                else r=mid;
            }
            res+=l;
        }
        cout<<res<<"\n";
    }
}