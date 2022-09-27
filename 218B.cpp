#include <bits/stdc++.h>
using namespace std;
int max(vector<int>v, int n){
    sort(v.begin(),v.end(),greater<int>());
    int maximum=0,index=0;
    while(n--){
        if(v[index]<=0) index++;
        maximum+=v[index];
        v[index]-=1;
        sort(v.begin(),v.end(),greater<int>());
    } return maximum;
}
int min(vector<int>v, int n){
    sort(v.begin(),v.end());
    int minimum=0,index=0;
    while(n--){
        if(v[index]<=0) index++;
        minimum+=v[index];
        v[index]-=1;
        sort(v.begin(),v.end());
    } return minimum;
}
int main(){
    int n,m; cin>>n>>m;
    vector<int>v(m);
    for(int i=0;i<m;i++) cin>>v[i];
    cout<<max(v,n)<<' '<<min(v,n);
}