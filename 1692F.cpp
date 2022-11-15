#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return; }
void solve(){
    int n; cin>>n;
    vector<int>v;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        string x; cin>>x;
        int len=x.length();
        if(mp[x[len-1]-48]<3){
            mp[x[len-1]-48]++;
            v.push_back(x[len-1]-48);
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                if((v[i]+v[j]+v[k])%10==3) print("YES")
            }
        }
    }
    print("NO")
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}