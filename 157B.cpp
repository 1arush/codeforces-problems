#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
void solve(){
    int n; cin>>n;
    double d=0;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n-1;i+=2){
        d+=(v[i]+v[i+1])*(v[i]-v[i+1]);
    }
    if(n%2) d+=v[n-1]*v[n-1];
    d*=3.1415926535;
    cout<<fixed<<setprecision(6)<<d;
}
int main(){
    solve();
}