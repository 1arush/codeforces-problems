#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; continue; }
bool isAP(vector<int>v){
    if(v.size()==1) return 1;
    int d=v[1]-v[0];
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]-v[i]!=d) return 0;
    }
    return 1;
}
int main(){
    int n; cin>>n;
    map<int,vector<int>>mp,mp1;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x].push_back(i+1);
    }
    for(auto p:mp){
        if(isAP(p.second)){
            mp1[p.first]=p.second;
        }
    } cout<<mp1.size()<<'\n';
    for(auto p:mp1){
        cout<<p.first<<' ';
        if(p.second.size()==1) print(0)
        print(p.second[1]-p.second[0]);
    }
}