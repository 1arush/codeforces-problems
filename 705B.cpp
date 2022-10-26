#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        sum+=(x-1)%2;
        if(sum%2==0) cout<<"2\n";
        else cout<<"1\n";
        sum=sum%2;
    }
}