#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int inp=0;inp<=n-1;inp++) cin>>v[inp];
        int min=v[n-1],days=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]<=min) min=v[i];
            else days++;
        } cout<<days<<'\n';
    }
}
