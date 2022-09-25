#include <iostream>
using namespace std;
int main(){
    int n,sum=0; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i]; sum+=a[i];
    }
    int cpsr=0,temp=a[0]; sum-=a[0];
    for(int i=1;i<=n-1;i++){
        if(temp==sum) cpsr++;
        temp+=a[i];
        sum-=a[i];
    }
    cout<<cpsr;
}