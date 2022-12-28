#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<' '; out++; }
int out=0;
int main(){
    int n,ne=0,zero=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i]; if(v[i]<0) ne++;
        if(v[i]==0) zero++;
    }
    if(n==1){ cout<<v.front(); return 0; }
    if(ne==1 and n==ne+zero){ cout<<0; return 0;}
    for(int i=0;i<n;i++) if(v[i]>0) print(v[i])
    if(ne%2){
        int m=100,done=-1;
        for(int i=0;i<n;i++){
            if(v[i]<0) m=min(-v[i],m);
        }
        for(int i=0;i<n;i++){
            if(v[i]<0 and done==-1 and v[i]==-m){ done=0; continue; }
            if(v[i]<0) print(v[i])
        }
    }
    else for(int i=0;i<n;i++) if(v[i]<0) print(v[i])
    if(out==0) cout<<0;
}