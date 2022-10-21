#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    map<int,int>M;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x==1) M[1]++;
        else if(x<=2048 and x%2==0) M[x]++;
    }
    if(M[2048]>=1) goto e;
    for(auto p : M){
        if(p.first>=2048) break;
        M[2*p.first]+=p.second/2;
    }
e:  if(M[2048]>=1) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}