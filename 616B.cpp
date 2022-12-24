#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,cost=0; cin>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++){
        int y=1e+9;
        for(int i=0;i<m;i++){
            int x; cin>>x; y=min(x,y);
        } v.push_back(y);
    }
    for(int i=0;i<n;i++) cost=max(cost,v[i]);
    cout<<cost;
}