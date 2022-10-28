#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define o return 0;
void print(ll l){
    cout<<l<<' '<<l+1<<' '<<l+2;
}
int main(){
    ll l,r; cin>>l>>r;
    if(r-l<2){
        cout<<-1; o
    }
    if(l%2==0){
        print(l); o
    }
    else if(r-l>2){
        print(l+1); o
    }
    cout<<-1; 
}