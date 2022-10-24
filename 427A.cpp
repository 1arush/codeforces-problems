#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int curr=0,ans=0;
    for(int i=0;i<n;i++){
        if(v[i]==-1 and curr==0) ans++;
        else if(v[i]==-1) curr--;
        else if(v[i]>=1) curr+=v[i];
    }
    cout<<ans<<"\n";
}