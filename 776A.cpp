#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b; cin>>a>>b;
    cout<<a<<' '<<b<<'\n';
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string x,y; cin>>x>>y;
        if(x==a) a=y;
        else b=y;
        cout<<a<<' '<<b<<'\n';
    }
}