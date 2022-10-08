#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,k,n; cin>>y>>k>>n;
    int x=k-y%k;
    if(y>=n){
        cout<<-1; return 0;
    } bool done=0;
    while(x+y<=n){
        cout<<x<<' ';
        done=1; x+=k;
    }
    if(!done) cout<<-1;
}