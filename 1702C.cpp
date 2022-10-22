#include <bits/stdc++.h>
using namespace std;
#define p pair<int,int>
void solve(){
    int n,k; cin>>n>>k;
    map<int,p>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(!mp.count(x)) mp[x]=make_pair(i,i);
        else mp[x].second=i;
    }
    for(int i=0;i<k;i++){
        int l,r; cin>>l>>r;
        if(mp.find(r)==mp.end() or mp.find(l)==mp.end()) cout<<"NO\n";
        else if(mp[l].first > mp[r].second) cout<<"NO\n";
        else cout<<"YES\n";
    }
}
int main(){
    int t; cin>>t;
    while(t--) solve();
}