#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    #ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int _;
    cin>>_;
    while(_--){
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        // store previous d values and choose minimum
        vector<int> ans(n);
        for(int j=0; j<n; ++j){
            vector<int> a(m), dp(m,1);
            for(auto &x:a) cin>>x;
            multiset<int> ms;
            ms.insert(1);
            for(int i=1; i<m; ++i){
                int c=a[i]+1;
                int v=*ms.begin();
                v+=c;
                dp[i]=v;
                if((int)ms.size()<=d){
                    ms.insert(v);
                } else{
                    int ix=i-d-1;
                    ms.erase(ms.find(dp[ix]));
                    ms.insert(dp[i]);
                }
            }
            ans[j]=dp[m-1];
        }
        int res=0, p=0;
        for(int i=0; i<n; ++i){
            if(i<k){
                res+=ans[i], p+=ans[i];
            } else{
                p+=ans[i]-ans[i-k];
                res=min(res,p);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
