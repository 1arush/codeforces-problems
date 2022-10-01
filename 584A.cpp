#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t; cin>>n>>t;
    int s=1;
    if(t<10){
        for(int i=0;i<n;i++){
            cout<<s*t<<"";
        }
    }
    if(t==10){
        if(n==1)    cout<<-1;
        else{
            for(int i=0;i<n-1;i++){
                cout<<1<<"";
            }
            cout<<0;
        }
    }
}