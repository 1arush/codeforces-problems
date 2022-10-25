#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n+1);
    int k=n;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        v[t]=1;
        while(v[k]!=0){
            cout<<k<<' '; k--;
        }
        cout<<'\n';
    }
}