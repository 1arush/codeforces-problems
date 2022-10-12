#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int x,n,m; cin>>x>>n>>m;
        while(n>0){
            if(x>=20) x=x/2+10;
            else break;
            n--;
        }
        // cout<<x;
        while(m>0){
            x-=10;
            m--;
        }
        if(x>0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;    
    }
}