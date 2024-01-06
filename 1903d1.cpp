// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> A(n);
    for(auto &x:A) cin>>x;
    while(q--){
        vector<int> a=A;
        int k;
        cin>>k;
        int ans=0, v=(1ll<<61)-1;
        for(int bit=61; ~bit; --bit){
            int d=k;
            for(int i=0; i<n; ++i){
                if((a[i]>>bit)&1) continue;
                d-=(1ll<<bit)-(a[i]&v);
                if(d<0) break;
            }
            if(d>=0){
                for(int i=0; i<n; ++i){
                    if((a[i]>>bit)&1) continue;
                    a[i]&=(~v);
                    a[i]|=(1ll<<bit);
                }
                ans|=(1ll<<bit), k=d;
            }
            v&=(v>>1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
