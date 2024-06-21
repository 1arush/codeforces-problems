#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n;
        cin>>n;
        vector<int> a(n+1), seg(n+2);
        int ans=0;
        for(int i=1; i<=n; ++i){
                cin>>a[i];
        }        
        auto add=[&](int l, int r, int v)-> void {
                seg[l]+=v, seg[r+1]-=v;
        };
        for(int i=1; i<n; ++i){
                int d=a[i+1]-a[i];
                ans+=abs(d);
                if(d<0){
                        add(1,i,d);
                }else{
                        add(i+1,n,-d);
                }
        }
        for(int i=1; i<=n; ++i){
                seg[i]+=seg[i-1];
        }
        ans+=abs(a[1]+seg[1]);
        cout<<ans<<'\n';
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
