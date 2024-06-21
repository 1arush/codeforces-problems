#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n, m;
        cin>>n>>m;
        int p=(n-m)/(m+1);
        int ans=n*(n+1)/2;
        int r=(n-m)%(m+1);
        ans-=(m+1-r)*p*(p+1)/2;
        ans-=r*(p+1)*(p+2)/2;
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
