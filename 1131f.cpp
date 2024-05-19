#include <bits/stdc++.h>
#define int int64_t
#define dbg(x) cout<<(#x)<<' '<<(x)<<'\n'
using namespace std;

struct Node {
        int val;
        Node *next, *last;
        Node(int x){
                this->val=x;
                this->next=NULL;
                this->last=this;
        }
};

Node* add(Node *root, Node *t){
        if(!root) return t;
        root->last->next=t;
        root->last=t->last;
        return root;
}

vector<Node*> l;

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
                        // modify to take care of links
                        // merge two lists in O(1)
                        l[a]=add(l[a],l[b]), l[b]=NULL;
                        return 1;
                }
                return 0;
        }
};

void solve_test(){
        int n;
        cin>>n;
        l.resize(n);
        DSU dsu(n);
        for(int i=0; i<n; ++i){
                l[i]=new Node(i);
        }
        for(int i=0; i<n-1; ++i){
                int u, v;
                cin>>u>>v, --u, --v;
                dsu.unite(u,v);
        }
        int res=dsu.leader(0);
        Node *p=l[res];
        while(p){
                cout<<p->val+1<<' ';
                p=p->next;
        }
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int _test=1;
        // cin>>_test;
        while(_test--){
                solve_test();
        }
        return 0;
}
