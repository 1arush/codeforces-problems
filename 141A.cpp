#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return 0; }
int main(){
    string a,b,s; cin>>a>>b>>s;
    map<char,int>mp;
    for(auto c:a) mp[c]++;
    for(auto c:b) mp[c]++;
    for(auto c:s) mp[c]--;
    for(auto p:mp){
        if(p.second!=0) print("NO")
    } print("YES")
}