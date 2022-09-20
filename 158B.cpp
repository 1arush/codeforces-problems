#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    int taxi=mp[4]+mp[3]+mp[2]/2;
    mp[1]-=mp[3];
    if(mp[2]%2==1){
        mp[1]-=2; taxi+=1;
    }
    if(mp[1]>0){
        taxi+=(mp[1]+3)/4;
    }
    cout<<taxi;
}