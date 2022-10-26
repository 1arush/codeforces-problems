#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b; cin>>n>>a>>b;
    if(n==0) cout<<0;
    else if(a+b<n) cout<<b+1;
    else cout<<n-a;
}