#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n, k, A, B;
vector<int> a;

int F(int l, int r){
        int gt=upper_bound(a.begin(),a.end(),r)-a.begin();
        int lt=lower_bound(a.begin(),a.end(),l)-a.begin();
        int cnt=max(0ll,gt-lt);
        if(cnt==0) return A;
        int d=B*cnt*(r-l+1);
        if(r==l) return d;
        int m=(l+r)/2;  
        int left=F(l,m), right=F(m+1,r);
        return min(d,left+right);
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        cin>>n>>k>>A>>B;
        a.resize(k);
        for(int i=0; i<k; ++i){
                cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans=F(1,(1ll<<n));
        cout<<ans<<'\n';
        return 0;
}
