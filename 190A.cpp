#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    if(n==0 || m==0){
        if(n==0){
            if(m==0) cout<<"0 0";
            else cout<<"Impossible";
        }
        else if(m==0) cout<<n<<' '<<n;
        return 0;
    }
    if(n>=m) cout<<n<<' '<<n+m-1;
    else cout<<n*((m-n)/n)+n+(m-n)%n<<' '<<n+m-1;
}