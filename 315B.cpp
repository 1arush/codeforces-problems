#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int a[n],sum1[n];
    for(int i=0;i<n;i++){
        cin>>a[i]; sum1[i]=0;
    }
    int sum=0;
    while(m--){
        int t; cin>>t;
        if(t==1){
            int v,x; cin>>v>>x;
            a[v-1]=x-sum;
        }
        if(t==2){
            int y; cin>>y;
            sum+=y;
        }
        if(t==3){
            int q; cin>>q;
            cout<<a[q-1]+sum<<'\n';
        }
    }
}