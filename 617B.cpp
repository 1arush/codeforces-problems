#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n, comb=1; cin>>n;
    vector<int>ch(n);
    for(int i=0;i<n;i++) cin>>ch[i];
    int i=0, l, r;
    while(i<n and ch[i]==0) i++;
    l=i; i=n-1;
    while(i>=0 and ch[i]==0) i--; r=i; i=l;
    if(l==n) goto l;
    while(i<=r){
        int j=i+1;
        while(j<=r and ch[j]!=1) j++;
        comb*=(j-i);
        i=j;
    }
    cout<<comb; return 0;
l:  cout<<0;
}