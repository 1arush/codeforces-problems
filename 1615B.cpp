#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int maxi=200005;
int main(){
    vector<vector<int>>v(maxi,vector<int>(19));
    for(int i=1;i<maxi;i++){
        for(int j=0;j<=19;j++){
            v[i][j]=v[i-1][j];
            if(i & (1<<j)) v[i][j]++;
        }
    }
    int t; cin>>t;
    while(t--){
        int l,r,ans=0; cin>>l>>r;
        // ans = maximum no of 1s in the i-th bit in [0,18]
        for(int i=0;i<=19;i++){
            ans=max(ans,v[r][i]-v[l-1][i]);
        }
        cout<<(r-l+1)-ans<<'\n';
    }
}