#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int h=0,N=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    for(auto p : mp){
        if(p.second>h) h=p.second; 
        N++;
    }
    cout<<h<<' '<<N;
}
int main(){
    int n; cin>>n;
    solve(n);
}