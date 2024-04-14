#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _test;
        cin>>_test;
        while(_test--){
                int n;
                cin>>n;
                int ans=0;
                for(int i=1; i<=n; ++i){
                        ans+=i*(2*i-1);
                }
                cout<<ans<<' '<<2*n<<'\n';
                for(int i=n; i; --i){
                        cout<<2<<' '<<i<<' ';
                        for(int j=1; j<=n; ++j){
                                cout<<j<<' ';
                        }
                        cout<<'\n';
                        cout<<1<<' '<<i<<' ';
                        for(int j=1; j<=n; ++j){
                                cout<<j<<' ';
                        }
                        cout<<'\n';
                }
        }
        return 0;
}
