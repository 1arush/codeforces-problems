#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Segtree {
        int sz=1, NO_OPERATION=1e16, NEUTRAL=0;  // important!
        vector<int> lazy, tree;
        void init(int n){
                while(sz<n) sz<<=1;
                lazy.assign(2*sz,NO_OPERATION);
                tree.assign(2*sz,0LL);  // initialize
        }
        int merge(int a, int b){
                return a+b;
        }
        int apply(int a, int b, int len){  // sum 
                if(b==NO_OPERATION) return a;
                return b*len;
        }
        void push(int x, int lx, int rx){
                if(rx-lx==1 || lazy[x]==NO_OPERATION) return;
                int m=(lx+rx)/2;
                tree[2*x+1]=apply(tree[2*x+1],lazy[x],m-lx);
                lazy[2*x+1]=apply(lazy[2*x+1],lazy[x],1);
                tree[2*x+2]=apply(tree[2*x+2],lazy[x],rx-m);
                lazy[2*x+2]=apply(lazy[2*x+2],lazy[x],1);
                lazy[x]=NO_OPERATION;
        }
        void modify(int l, int r, int v, int x, int lx, int rx){
                push(x,lx,rx); 
                if(rx<=l || lx>=r) return;
                if(lx>=l && rx<=r){
                        lazy[x]=apply(lazy[x],v,1);
                        tree[x]=apply(tree[x],v,rx-lx); 
                        return;
                }
                int m=(lx+rx)/2;
                modify(l,r,v,2*x+1,lx,m);
                modify(l,r,v,2*x+2,m,rx);
                tree[x]=apply(merge(tree[2*x+1],tree[2*x+2]),lazy[x],rx-lx);
        }
        int calc(int l, int r, int x, int lx, int rx){
                push(x,lx,rx);
                if(rx<=l || lx>=r) return NEUTRAL;
                if(lx>=l && rx<=r) return tree[x];
                int m=(lx+rx)/2;
                auto m1=calc(l,r,2*x+1,lx,m);
                auto m2=calc(l,r,2*x+2,m,rx);
                return apply(merge(m1,m2),lazy[x],min(rx,r)-max(lx,l));
        }
        void modify(int l, int r, int v){
                modify(l,r+1,v,0,0,sz);
        }
        int calc(int l, int r){
                return calc(l,r+1,0,0,sz);
        }
};

void solve_test(){
        int n, q;
        cin>>n>>q;
        vector<Segtree> st(26);
        for(int i=0; i<26; ++i){
                st[i].init(n);
        }
        string s;
        cin>>s;
        for(int i=0; i<n; ++i){
                int c=s[i]-'a';
                st[c].modify(i,i,1);
        }
        while(q--){
                int l, r, v;
                cin>>l>>r>>v, --l, --r;
                vector<int> cnt(26);
                for(int i=0; i<26; ++i){
                        cnt[i]+=st[i].calc(l,r);
                        st[i].modify(l,r,0);
                }
                vector<int> itr(26);
                iota(itr.begin(),itr.end(),0);
                if(!v){
                        reverse(itr.begin(),itr.end());
                }
                int p=l;
                for(int c:itr){
                        if(cnt[c]==0) continue;
                        st[c].modify(p,p+cnt[c]-1,1);
                        p+=cnt[c];
                }
        }
        string ans=string(n,'a');
        for(int c=0; c<26; ++c){
                for(int i=0; i<n; ++i){
                        if(st[c].calc(i,i)){
                                ans[i]=char(c+'a');
                        }
                }
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
