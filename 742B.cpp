#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n,x;
    cin>>n>>x;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    long long ans=0;
    for(int i=0; i<n; i++){
        if(x==0) ans+=mp[a[i]]-1;
        else ans+=mp[a[i]^x];
    }
    ans/=2;
    cout<<ans<<'\n';
    return 0;
}