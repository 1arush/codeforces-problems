#include <bits/stdc++.h>
using namespace std;
// making a general formula for sequence obtained
int main(){
    int n; cin>>n;
    if(n==1){
        cout<<3; return 0;
    }
    n-=2;
    int arr[3]={5,7,8};
    int n1=n/3;
    n=n-3*n1;
    cout<<arr[n]+4*n1;
}