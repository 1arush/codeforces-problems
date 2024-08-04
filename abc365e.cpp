#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1; i<=n; ++i){
                cin>>a[i];
        }
        int ans=0;
        for(int b=30; ~b; --b){
                // how many subarrays have xor
                vector<int> c(n+1), pf(n+1);
                for(int i=1; i<=n; ++i){
                        if(a[i]&(1ll<<b)) c[i]=1;
                }
                vector<int> cnt(2);
                cnt[0]=1;
                int ret=0;
                for(int i=1; i<=n; ++i){
                        pf[i]=pf[i-1]^c[i];
                        int d=pf[i]^1;
                        ret+=cnt[d];
                        if(pf[i-1]==d) --ret;
                        ++cnt[pf[i]];
                }
                ans+=(1ll<<b)*ret;
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        // cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
