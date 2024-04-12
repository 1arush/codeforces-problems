#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN=5005;

int fen[MAXN], s[MAXN], n;

void add(int x, int v){
        for(; x<=n; x+=(x&-x)) fen[x]+=v;
}

int get(int x){
        int ret=0;
        for(; x>0; x-=(x&-x)) ret+=fen[x];
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);
 
        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif
 
        int _;
        cin>>_;
        while(_--){
                cin>>n;
                for(int i=1; i<=n; ++i){
                        char c;
                        cin>>c;
                        s[i]=c-'0';
                }
                for(int k=n; ~k; --k){
                        bool f=1;
                        for(int i=0; i<=n; ++i) fen[i]=0;
                        for(int i=1; i+k-1<=n; ++i){
                                int upd=get(i)&1;
                                int c=s[i]^upd;
                                if(!c){
                                        add(i,1);
                                        add(i+k,-1);
                                }
                        }
                        for(int i=n-k+1; i<=n; ++i){
                                int upd=get(i)&1;
                                int c=s[i]^upd;
                                if(!c){
                                        f=0; break;
                                }
                        }
                        if(f){
                                cout<<k<<'\n';
                                break;
                        }
                }
        }
        return 0;
}
