#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n,x;
    cin>>n>>x;
    multiset<int> a;
    vector<int> b(n);
    for(int i=0; i<n; i++){
        int y;
        cin>>y;
        a.insert(y);
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    int ans=0;
    for(int i=0; i<n; i++){
        // find smallest t, such that b[i] + t >= x
        auto f=a.lower_bound(x-b[i]);
        if(f==a.end()) continue;
        a.erase(f);
        ++ans;
    }
    cout<<1<<' '<<ans;
    return 0;
}