#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        if(i==0) cout<<v[i+1]-v[i]<<' '<<v[n-1]-v[0]<<'\n';
        else if(i==n-1) cout<<v[i]-v[i-1]<<' '<<v[n-1]-v[0]<<'\n';
        else{
            cout<<min(abs(v[i]-v[i-1]),abs(v[i+1]-v[i]))<<' ';
            cout<<max(abs(v[n-1]-v[i]),abs(v[i]-v[0]))<<'\n';
        }
    }
}