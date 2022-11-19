#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; int k;
    cin>>s>>k;
    map<char,int>mp;
    for(auto c:s) mp[c]++;
    int sz=mp.size();    
    vector<pair<char,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[](pair<char,int>a,pair<char,int>b){return a.second<b.second;});
    map<char,int>rem;
    for(int i=0;i<v.size() and k>0;i++){
        if(v[i].second>k){
            rem[v[i].first]=k; break;
        }
        else{
            rem[v[i].first]=v[i].second;
            k-=v[i].second; sz--;
        }
    }
    cout<<sz<<'\n';
    for(auto c:s){
        if(rem[c]>0){
            rem[c]--;
        }
        else cout<<c;
    }
}