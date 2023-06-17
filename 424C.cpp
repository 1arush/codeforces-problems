#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin>>n;
    int res=0;
    vector<int> rem(n+1,0);
    for(int i=0; i<n; i++){
        int y; 
        cin>>y;
        res^=y;
    }
    if(n%2) res^=0;
    for(int i=2; i<=n; i++){
        int d=n/i, r=n%i;
        if(d&1){
            rem[0]++; rem[i]--;
        }
        if(r){
            rem[1]++; rem[r+1]--;
        }
    }
    for(int i=1; i<n; i++){
        rem[i]+=rem[i-1];
        if(rem[i]&1) res^=i;
        // debug(rem[i]);
    }
    cout<<res<<'\n';
    return 0;
}