#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define pii pair<ll,int>
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int ttc=1;
    cin>>ttc;
    while(ttc--){
        int n,k; cin>>n>>k;
        ll a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        vector<pii> I(n);
        for(int i=0; i<n; i++){
            I[i].ff=(n-i-1)-a[i], I[i].ss=i;
        }
        sort(I.begin(),I.end());
        ll res=0;
        vector<bool> mark(n+1);
        for(int i=0; i<k; i++){
            mark[I[i].ss]=true;
            a[I[i].ss]=(ll)n-i-1;
        }
        ll cnt=0;
        for(int i=n-1; i>=0; i--){
            a[i]-=cnt;
            if(mark[i]) ++cnt;
        }
        for(int i=0; i<n; i++) res+=a[i];
        cout<<res<<"\n";   
    }
}