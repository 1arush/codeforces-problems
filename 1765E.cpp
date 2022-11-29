#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; continue; }
int main(){
    int t; cin>>t;
    while(t--){
        int n,a,b; cin>>n>>a>>b;
        if(a>b) print(1)
        if(n%a==0) print(n/a)
        else print(n/a+1)
    }
}