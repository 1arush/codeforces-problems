#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long int n; cin>>n;
        if(n%2==0) cout<<4*n+1<<'\n';
        else if((n-1)%4==0) cout<<2*n+1<<'\n';
        else cout<<n+1<<'\n';
    }
}