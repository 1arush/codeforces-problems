#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ct=0; cin>>n>>k;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        v.push_back(make_pair(x,i));
    }
    vector<int>indexes;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i].first<=k){
            ct++; k-=v[i].first;
            indexes.push_back(v[i].second);
        }
        else break;
    }
    cout<<ct<<'\n';
    for(int i=0;i<indexes.size();i++) cout<<indexes[i]<<' ';
}