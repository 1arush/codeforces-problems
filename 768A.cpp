#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ct=0; cin>>n;
    vector<int>v(n);
    int mini=INT32_MAX,maxi=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        maxi=max(v[i],maxi);
        mini=min(v[i],mini);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n-1;i++){
        if(mini<v[i] and v[i]<maxi) ct++;
    }
    cout<<ct;
}