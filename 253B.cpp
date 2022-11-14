#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n,ret=5e+8; cin>>n;
    map<int,int>m;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int x; cin>>x; m[x]++;
    }
    for(auto p:m) v.push_back(make_pair(p.first,p.second));
    vector<int>lSum;
    for(int i=0;i<v.size();i++){
        if(i==0) lSum.push_back(0);
        else lSum.push_back(v[i-1].second+lSum.back());
    }
    for(int i=0;i<v.size();i++){
        int ct=0;
        for(int j=v.size()-1;j>=0;j--){
            if(v[j].first<=2*v[i].first) break;
            ct+=v[j].second;
        } ct+=lSum[i];
        ret=min(ret,ct);
    }
    cout<<ret<<'\n';
}