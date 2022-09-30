#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n),ret(n);
    for(int u=0;u<=n-1;u++) cin>>v[u];
    int max=-1;
    for(int i=n-1;i>=0;i--){
        if(v[i]>max){
            ret[n-i-1]=0; max=v[i];
        }
        else ret[n-i-1]=max-v[i]+1;
    }
    for(int i=n-1;i>=0;i--) cout<<ret[i]<<' ';
}