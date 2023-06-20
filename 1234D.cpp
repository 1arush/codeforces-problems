#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

vector<vector<int>> seg;
set<int> cnt;
int sz=1, n;

void upd(int i, char v, int x, int lx, int rx){
    if(rx-lx==1){
        seg[x].assign(26,0);
        seg[x][v-'a']++; return;
    }
    int m=(lx+rx)/2;
    if(i<m){
        upd(i, v, 2*x+1, lx, m);
    }
    else{
        upd(i, v, 2*x+2, m, rx);
    }
    seg[x].assign(26,0);
    for(int i=0; i<26; i++){
        seg[x][i]=seg[2*x+1][i]+seg[2*x+2][i];
    }
}

void get(int l, int r, int x, int lx, int rx){
    if(rx<=l || lx>=r) return;
    if(rx<=r && lx>=l){
        for(int i=0; i<26; i++){
            if(seg[x][i]) cnt.insert(i);
        }
        return;
    }
    int m=(lx+rx)/2;
    get(l, r, 2*x+1, lx, m);
    get(l, r, 2*x+2, m, rx);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    string s; 
    cin>>s;
    n=s.size();
    while(sz<n) sz<<=1;
    seg.assign(2*sz, vector<int> (26,0));
    for(int i=0; i<n; i++){
        upd(i,s[i],0,0,sz);
    }
    int q; 
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i;
            char c;
            cin>>i>>c;
            upd(i-1,c,0,0,sz);
        }
        else{
            int l,r;
            cin>>l>>r;
            get(l-1,r,0,0,sz);
            cout<<cnt.size()<<'\n';
            cnt.clear();
        }
    }
    return 0;
}