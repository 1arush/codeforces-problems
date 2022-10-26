#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
int main(){
    int n, mini=0; cin>>n;
    int occur[200005];
    fill(occur,occur+200005,1e+8);
    forn(i,n){
        int x; cin>>x;
        occur[x]=i;
    }
    forn(i,200005){
        if(occur[i]<occur[mini]) mini=i;
    }
    cout<<mini;
}