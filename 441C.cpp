#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k; cin>>n>>m>>k;
    int x=1,y=1,l;
    for(int i=1;i<=k;i++){
        if(i!=k) l=(n*m)/k;
        else l=(n*m)/k+(n*m)%k;
        cout<<l<<' ';
        for(int i=0;i<l;i++){
            cout<<x<<' '<<y<<' ';
            if(x%2) y++;
            else y--;
            if(y<1){ y=1; x++; }
            if(y>m){ y=m; x++; }
        } cout<<'\n';
    }
}