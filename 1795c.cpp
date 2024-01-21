// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n), b(n), pf(n);
        for(auto &x:a) cin>>x;
        for(int i=0; i<n; ++i){
            cin>>b[i], pf[i]=(i ? pf[i-1] : 0ll)+b[i];
        }
        auto sum=[&](int l, int r){
            return pf[r]-(l>0 ? pf[l-1] : 0ll);
        };
        vector<int> t(n+1), add(n+1);
        for(int i=0; i<n; ++i){
            int l=i, r=n-1;
            auto good=[&](int x){
                return sum(i,x)<=a[i];
            };
            while(r>l+1){
                int mid=(l+r)/2;
                if(good(mid)) l=mid;
                else r=mid;
            }
            if(!good(l)){
                add[i]+=a[i];
            }
            else{
                if(good(l+1) && l+1<n) ++l;
                t[i]++, t[l+1]--;
                assert(l<n);
                add[l+1]+=a[i]-sum(i,l);
            }
        }
        for(int i=1; i<=n; ++i) t[i]+=t[i-1];
        for(int i=0; i<n; ++i) cout<<t[i]*b[i]+add[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
