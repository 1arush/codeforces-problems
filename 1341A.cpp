#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
        int min=n*(a-b),max=n*(a+b);
        if(min>c+d or max<c-d) cout<<"No\n";
        else cout<<"Yes\n";  
    }
}