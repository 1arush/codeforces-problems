#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>digit={8,4,2,6};
    if(n!=0) cout<<digit[(n-1)%4];
    else cout<<1;
}