#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int _test;
        cin>>_test;
        while(_test--){
                int r;
                cin>>r;
                int ans=0;
                auto calc=[&](int R)-> int {
                        // # point dist < R
                        int ret=0;
                        for(int x=-R+1; x<R; ++x){
                                // x*x+y*y<R*R
                                long double sq=sqrtl(R*R-x*x);
                                int rp=((int)sq==sq ? (int)sq-1 : sq);
                                sq*=-1;
                                int lp=((int)sq==sq ? sq+1 : (int)sq);
                                ret+=max(0ll,rp-lp+1);
                        }
                        return ret;
                };
                ans+=calc(r+1)-calc(r);
                cout<<ans<<'\n';
        }
        return 0;
}
