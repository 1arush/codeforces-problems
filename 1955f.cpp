#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int c[5];

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                int ans=0;
                for(int i=1; i<5; ++i){
                        cin>>c[i];
                        ans+=c[i]/2;
                        c[i]&=1;
                }
                ans+=min({c[1],c[2],c[3]});
                cout<<ans<<'\n';
        }
        return 0;
}
