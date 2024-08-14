#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n, m, k;
        cin>>n>>m>>k;
        // for each cell, count how many subrectangles contain it
        vector<int> v;
        for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j){
                        // l<=i<=l+k-1
                        int c=(min(i,n-k+1)-max(1ll,i-k+1)+1)*(min(j,m-k+1)-max(1ll,j-k+1)+1);
                        v.push_back(c);
                }
        }
        sort(v.rbegin(),v.rend());
        int w;
        cin>>w;
        vector<int> mon(w);
        for(int i=0; i<w; ++i){
                cin>>mon[i];
        }
        sort(mon.rbegin(),mon.rend());
        int ans=0;
        for(int i=0; i<w; ++i){
                ans+=v[i]*mon[i];
        }
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
