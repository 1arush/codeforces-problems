#include <bits/stdc++.h>
using namespace std;
#define print(i) { cout<<i; return; }
void solve(){
    int n,y=-1; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n-1;i++){
        if(v[i+1]>=v[i]) continue;
        else{
            y=i; break;
        }
    }
    if(y==-1) print(0);
    y++;
    for(int i=y;i<n-1;i++){
        if(v[i+1]>=v[i] and v[i]<=v[0] and v[i+1]<=v[0]) continue;
        else print(-1)
    }
    if(v[y]<=v[0]) print(n-y)
    else print(-1)
}
int main(){
    solve();
}