#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    int n,q; cin>>n>>q;
    vector<int>a;
    vector<ll>b;
    b.push_back(0);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        b.push_back(b.back()+x);
        if(i==0) a.push_back(x);
        else{
            int R=max(a.back(),x);
            a.push_back(R);
        }
    }
    for(int i=0;i<q;i++){
        int x; cin>>x;
        int J=upper_bound(a.begin(),a.end(),x)-a.begin();
        cout<<b[J]<<' ';
    }
    cout<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}