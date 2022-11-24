#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x; return 0; }
#define forn(i,n) for(int i=0;i<n;i++)
int main(){
    int n,m; cin>>n>>m;
    set<int>s;
    forn(i,n){
        string v; cin>>v;
        int l,r;
        forn(j,m){
            if(v[j]=='G') l=j;
            if(v[j]=='S') r=j;
        }
        if(l>r) print(-1)
        s.insert(r-l);
    }
    cout<<s.size();    
}