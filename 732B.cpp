#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    int a[n];
    int S=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1]<k){
            S+=k-a[i+1]-a[i];
            a[i+1]+=k-a[i+1]-a[i];
        }
    }
    cout<<S<<"\n";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}