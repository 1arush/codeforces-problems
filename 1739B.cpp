#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return; }
void cute(){
    int n; cin>>n;
    vector<int>v(n),w;
    for(int i=0;i<n;i++) cin>>v[i];
    int prev=v[0]; 
    for(int i=1;i<n;i++){
        w.push_back(prev);
        int l=prev-v[i],r=prev+v[i];
        if(l>=0 && r>=0 && l!=r) print(-1)
        else if(l>=0) prev=l;
        else if(r>=0) prev=r;
        else print(-1)
    } 
    w.push_back(prev);
    for(int i=0;i<n;i++) cout<<w[i]<<' '; cout<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--) cute();
}