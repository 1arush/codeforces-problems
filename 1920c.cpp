// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        vector<int> d;
        for(int i=1; i*i<=n; ++i){
            if(n%i==0){
                d.push_back(i);
                if(i*i!=n) d.push_back(n/i);
            }
        }
        int ans=0;
        for(int k:d){
            int g=0;
            for(int i=0; i<k; ++i){
                for(int j=i+k; j<n; j+=k){
                    g=__gcd(g,abs(a[j]-a[i]));
                }
            }
            if(g!=1) ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
