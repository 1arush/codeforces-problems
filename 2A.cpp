#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,max=INT32_MIN; cin>>n;
    string s[n]; int a[n];
    map<string,int>m; // for final scores
    for(int i=0;i<n;i++){
        string name; int score;
        cin>>name>>score;
        s[i]=name; a[i]=score;
        m[name]+=score;
    }
    string winner;
    for(auto p:m){
        if(p.second>max) max=p.second;
    }
    map<string,int>mp; // for each instant
    for(int i=0;i<n;i++){
        mp[s[i]]+=a[i];
        if(mp[s[i]]>=max and m[s[i]]==max){
            winner=s[i]; break;
        }
    } cout<<winner;
}