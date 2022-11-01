#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,r; cin>>n;
    vector<int>in,u;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        in.push_back(x); u.push_back(x);
    }
    sort(u.begin(),u.end());
    for(l=0;l<n;l++){
        if(in[l]>in[l+1]) break;
    }
    for(r=n-1;r>=0;r--){
        if(u[r]!=in[r]) break;
    }
    for(int i=l;i<=(r+l)/2;i++) swap(in[i],in[r+l-i]);
    for(int i=l;i<=r;i++){
        if(in[i]!=u[i]){
            cout<<"no"; return 0;
        }
    }
    if(r==-1) cout<<"yes\n1 1";
    else cout<<"yes\n"<<++l<<' '<<++r;   
}