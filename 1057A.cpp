#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin>>n;
    ll a[n-1];
    for(ll i=0;i<n-1;i++){
        cin>>a[i];
    }
    vector<int>path;
    if(n>1) path.push_back(n);
    ll i=n-2;
    while(a[i]!=1){
        path.push_back(a[i]);
        i=a[i]-2;
    }
    path.push_back(1);
    for(int i=path.size()-1;i>=0;i--) cout<<path[i]<<' ';
}