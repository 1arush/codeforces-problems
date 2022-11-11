#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return; }
void solve(){
    int n,m=50,M=1; cin>>n;
    bool perfect=1,rev=1;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<m) m=v[i];
        if(v[i]>M) M=v[i];
        if(v[i]<v[i-1] and perfect and i>=1) perfect=0;
        if(v[i]>v[i-1] and rev and i>=1) rev=0;
    }
    if(perfect) print(0)
    if(rev) print(3)
    if(v[0]==M and v[n-1]==m) print(3)
    else if(v[0]!=m and v[n-1]!=M) print(2)
    else print(1)
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}