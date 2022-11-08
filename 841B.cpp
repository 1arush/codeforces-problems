#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return 0; }
int main(){
    int n,j=0; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x%2) j++;
    }
    if(j==0) print("Second");
    print("First")
}