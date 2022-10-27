#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n,k,val=0,ans=0; cin>>n>>k;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        val+=(y+1-x);
        vector<int>temp {x,y};
        v.pb(temp);
    }
    while(val%k!=0){
        val++; ans++;
    }
    cout<<ans;
}