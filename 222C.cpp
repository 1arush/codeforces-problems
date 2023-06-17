#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
const int N=1e7;
vector<int> lp(N+1,0);
vector<int> pr;

void precalc(){
    for(int i=2; i<=N; i++){
        if(lp[i]==0){
            lp[i]=i;
            pr.push_back(i);
        }
        for(int j=0; (long long)i*pr[j]<=N; j++){
            lp[i*pr[j]]=pr[j];
            if(pr[j]==lp[i]) break;
        }
    }
}

vector<int> r1(N+1), r2(N+1);

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    precalc();
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        int v;
        cin>>v;
        a[i]=v;
        while(v>1){
            r1[lp[v]]++; v/=lp[v];
        }
    }
    for(int i=0; i<m; i++){
        int v; 
        cin>>v;
        b[i]=v;
        while(v>1){
            r2[lp[v]]++; v/=lp[v];
        }
    }
    vector<int> g(N+1);
    for(int i=1; i<=N; i++) g[i]=min(r1[i],r2[i]);
    for(int i=0; i<n; i++){
        int k=a[i];
        while(k>1){
            if(g[lp[k]]){
                a[i]/=lp[k];
                g[lp[k]]--;
            }
            k/=lp[k];
        }
    }
    for(int i=1; i<=N; i++) g[i]=min(r1[i],r2[i]);
    for(int i=0; i<m; i++){
        int k=b[i];
        while(k>1){
            if(g[lp[k]]){
                b[i]/=lp[k];
                g[lp[k]]--;
            }
            k/=lp[k];
        }
    }
    cout<<n<<' '<<m<<'\n';
    for(int i=0; i<n; i++) cout<<a[i]<<' ';  
    cout<<'\n';
    for(int i=0; i<m; i++) cout<<b[i]<<' '; 
    return 0;
}