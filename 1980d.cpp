#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n;
        cin>>n;
        vector<int> a(n+1), b(n+1);
        for(int i=1; i<=n; ++i){
                cin>>a[i];
        }
        for(int i=1; i<=n-1; ++i){
                b[i]=__gcd(a[i],a[i+1]);
        }
        b[n]=1e9;
        // remove first
        if(is_sorted(b.begin()+2,b.end())){
                cout<<"YES\n";
                return;
        }
        // remove last
        if(is_sorted(b.begin()+1,b.begin()+n-1)){
                cout<<"YES\n";
                return;
        }
        int i=1, r=n;
        while(i+1<=n && b[i+1]>=b[i]){
                ++i;
        }
        while(r>0 && b[r-1]<=b[r]){
                --r;
        }
        for(int j=2; j<n; ++j){
                // remove a[j]
                // ... a[j-1] _ a[j+1] ...
                int g=__gcd(a[j-1],a[j+1]);
                if(j-2<=i && j+1>=r){
                        if(g>=b[j-2] && g<=b[j+1]){
                                cout<<"YES\n";
                                return;
                        }
                }
        }
        cout<<"NO\n";
}


int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
