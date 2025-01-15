#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n, m;
        cin>>n>>m;
        vector<string> a(n);
        for(int i=0; i<n; ++i){
                cin>>a[i];
        }
        if(n>3){
                cout<<"-1\n"; return;
        }   
        vector<int> to(m);
        for(int j=0; j<m; ++j){
                for(int i=0; i<n; ++i){
                        to[j]<<=1, to[j]+=a[i][j]=='1';
                }
        }
        int ans=n*m;
        auto bdiff=[&](int a, int b)-> int {
                return __builtin_popcount(a^b);
        };
        vector<int> pre(m);
        for(int m1=0; m1<(1<<n); ++m1){
                int cur=bdiff(m1,to[0]);
                pre[0]=m1;
                for(int j=1; j<m; ++j){
                        // try every mask?
                        int res=1e9;
                        auto chk=[&](int x, int y)-> bool {
                                bitset<4> b1(x), b2(y);
                                for(int i=0; i+1<n; ++i){
                                        int p=b1[i]^b1[i+1];
                                        int q=b2[i]^b2[i+1];
                                        if(p==q) return 0;
                                }
                                return 1;
                        };      
                        for(int m2=0; m2<(1<<n); ++m2){
                                if(!chk(pre[j-1],m2)) continue;
                                pre[j]=m2;
                                res=min(res,bdiff(to[j],m2));
                        }
                        cur+=res;
                }
                ans=min(ans,cur);
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
