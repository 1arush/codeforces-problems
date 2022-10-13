#include <bits/stdc++.h>
using namespace std;
int main(){
    string num; int n,k;
    cin>>n>>k>>num;
    if(k==0){
        cout<<num; return 0;
    }
    if(k==n){
        if(n==1) cout<<'0';
        else cout<<'1';
        for(int i=1;i<k;i++) cout<<'0';
        return 0;
    }
    int i=1;
    cout<<'1';
    if(num[0]!='1') k--;
    while(i<n and k>0){
        if(num[i]=='0'){
            i++; cout<<'0';
        }
        else{
            cout<<'0'; k--; i++;
        }
    }
    for(i;i<n;i++) cout<<num[i];
}