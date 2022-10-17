#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    vector<int>v(m);
    for(int i=1;i<=m;i++) cin>>v[i-1];
    sort(v.begin(),v.end());
    int E=v[m-1];
    for(int i=0;i<=m-n;i++){
        E=min(E,v[i+(n-1)]-v[i]);
    }
    cout<<E;
}