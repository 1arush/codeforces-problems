#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
int main(){
    int n,k; cin>>n>>k;
    vector<int>v(2*n+1);
    forn(i,2*n+1) cin>>v[i];
    for(int i=1;i<=2*n;i+=2){
        if(k==0) break;
        if(v[i]-v[i-1]>1 and v[i]-v[i+1]>1){
            v[i]--; k--;
        }
    }
    forn(i,2*n+1) cout<<v[i]<<' ';
}