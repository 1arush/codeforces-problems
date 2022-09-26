#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int m=1;
    if(a[0]!=1){
        cout<<1; return 0;
    }
    for(int i=0;i<=n-2;i++){
        if(a[i+1]-a[i]>1){
            m=a[i]+1; break;
        }
    }
    if(a[0]==1 and m==1) m=a[n-1]+1; // case: sorted order
    cout<<m;
}