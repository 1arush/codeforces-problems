#include <iostream>
using namespace std;
void revF(int a[], int n){
    for(int i=n-1;i>=1;i--) swap(a[i],a[i-1]);
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) a[i]=i+1;
    revF(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
}