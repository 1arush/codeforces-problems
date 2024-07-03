#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf=1e9;

struct Segtree {
        int sz=1;
        vector<int> tree;
        void init(int n){
                while(sz<n) sz<<=1;
                tree.assign(2*sz,0LL);
        }
        int merge(int a, int b){
                return std::max(a,b);
        }
        void modify(int i, int v, int x, int lx, int rx){
                if(rx-lx==1){
                        tree[x]=v; return;
                }
                int m=(lx+rx)/2;
                if(i<m){
                        modify(i,v,2*x+1,lx,m);
                }else{
                        modify(i,v,2*x+2,m,rx);
                }
                tree[x]=merge(tree[2*x+1],tree[2*x+2]);
        }
        int query(int l, int r, int x, int lx, int rx){
                if(lx>=r || rx<=l) return 0LL;
                if(lx>=l && rx<=r) return tree[x];
                int m=(lx+rx)/2;
                auto m1=query(l,r,2*x+1,lx,m);
                auto m2=query(l,r,2*x+2,m,rx);
                return merge(m1,m2);
        }
        int query(int l, int r){
                return query(l,r+1,0,0,sz);
        }
        void modify(int i, int v){
                modify(i,v,0,0,sz);
        }
};

void solve_test(){
        int n;
        cin>>n;
        Segtree st;
        st.init(n);
        vector<int> h(n), a(n);
        for(int i=0; i<n; ++i){
                cin>>h[i], --h[i];
        }
        for(int i=0; i<n; ++i){
                cin>>a[i];
        }
        vector<int> dp(n);
        for(int i=0; i<n; ++i){
                // ending at this index
                dp[h[i]]=a[i]+st.query(0,h[i]-1);
                st.modify(h[i],dp[h[i]]);
        }
        int ans=st.query(0,n-1);
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
