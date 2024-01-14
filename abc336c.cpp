// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin>>n;
    if(n==1){
        cout<<"0"; exit(0);
    }
    string res;
    n--;
    while(n){
        res+=char('0'+2*(n%5));
        n/=5;
    }
    reverse(res.begin(),res.end());
    cout<<res<<'\n';
    return 0;
}
