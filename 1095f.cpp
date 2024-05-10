#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct DSU {
        int n;
        vector<int> sz, p;
        DSU(int _n) : n(_n){
                sz.assign(n,1), p.resize(n);
                iota(p.begin(),p.end(),0);
        }
        int leader(int a){
                return (a==p[a] ? a : p[a]=leader(p[a]));
        }
        bool unite(int a, int b){
                a=leader(a), b=leader(b);
                if(sz[a]<sz[b]) swap(a,b);
                if(a!=b){
                        p[b]=a, sz[a]+=sz[b];
                        return 1;
                }
                return 0;
        }
};

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int n, m;
        cin>>n>>m;
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; ++i){
                cin>>a[i].first;
                a[i].second=i;
        }
        sort(a.begin(),a.end());
        vector<array<int,3>> edg(m);
        for(auto &[w,x,y]:edg){
                cin>>x>>y>>w, --x, --y;
        }
        sort(edg.begin(),edg.end());
        int ans=0, j=0;
        auto [val,ind]=a[0];
        DSU ds(n);
        for(int i=1; i<n; ){
                auto [av,v]=a[i];
                array<int,3> MAX {(int)1e15,0,0};
                auto [w,x,y]=(j<m ? edg[j] : MAX);
                if(val+av<w){
                        if(ds.unite(ind,v)){
                                ans+=(val+av);
                        }
                        ++i;
                }else if(w<val+av){
                        if(j<m && ds.unite(x,y)){
                                ans+=w;
                        }
                        ++j;
                }else{
                        if(ds.unite(ind,v)){
                                ans+=(val+av);
                                ++i;
                        }else if(j<m && ds.unite(x,y)){
                                ans+=w;
                                ++j;
                        }else{
                                ++i, ++j;
                        }
                }
        }
        cout<<ans<<'\n';
        return 0;
}
