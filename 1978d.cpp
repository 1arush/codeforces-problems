#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n, c;
        cin>>n>>c;
        vector<int> a(n), pf(n), sf(n+1);
        for(int i=0; i<n; ++i){
                cin>>a[i];
                if(!i) a[i]+=c;
                pf[i]=a[i]+(i ? pf[i-1] : 0ll);
        }        
        for(int i=n-1; ~i; --i){
                sf[i]=max(sf[i+1],a[i]);
        }
        int mx=*max_element(a.begin(),a.end());
        map<int,int> mp;
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
                if(a[i]==mx){
                        if(mp[a[i]]==0){
                                ans[i]=0;
                        }else{
                                ans[i]=i;
                        }
                        ++mp[a[i]];
                        continue;
                }
                ++mp[a[i]];
                if(mp[mx]>0){
                        ans[i]=i;
                }else{
                        if(pf[i]>=sf[i+1]){
                                ans[i]=i;
                        }else{
                                ans[i]=i+1;
                        }
                }
        }
        for(int x:ans){
                cout<<x<<' ';
        }
        cout<<'\n';
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
