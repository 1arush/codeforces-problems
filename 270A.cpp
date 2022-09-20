#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    // n=360/(180-A)
    for(int i=0;i<n;i++){
        int angle; cin>>angle;
        if(360%(180-angle)==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
