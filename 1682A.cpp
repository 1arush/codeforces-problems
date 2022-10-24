#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s; cin>>n>>s;
    char d=s[n/2];
    int i=n/2, ans=0;
    while(i<n and s[i]==d){
        i++; ans++;
    }
    ans=(n%2==0)?2*ans:2*ans-1;
    cout<<ans<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}