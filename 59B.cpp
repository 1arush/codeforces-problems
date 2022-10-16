#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v;
    int sum=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
        sum+=x;
    }
    sort(v.begin(),v.end());
    int fo=-1;
    for(int i=0;i<n;i++){
        if(v[i]%2!=0){
            fo=i; break;
        }
    }
    if(sum%2==0){
        if(fo==-1) cout<<0;
        else cout<<sum-v[fo];
    }
    else cout<<sum;
}