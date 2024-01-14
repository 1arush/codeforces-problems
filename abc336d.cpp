// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    vector<int> lm(n);
    iota(lm.begin(),lm.end(),0LL);
    int i=n-1, l=n-1;
    while(i>=0){
        while(l>=0 && a[l]>=(i-l+1)) --l;
        // cout<<i<<':'<<l<<'\n';
        lm[l+1]=max(lm[l+1],i); // inclusive
        --i;
    }
    // for(int i=0; i<n; ++i) cout<<lm[i]<<' ';
    // cout<<'\n';
    int ans=0;
    multiset<int> s;
    for(int i=0, r=0; i<n; ++i){
        while(r<n && a[r]>=(r-i+1)){
            s.insert(lm[r++]);
        }
        int mx=*prev(s.end());
        s.erase(s.find(lm[i]));
        ans=max(ans,(mx-i+2)/2);
    }
    ans=max(ans,1LL);
    cout<<ans<<'\n';
    return 0;
}
