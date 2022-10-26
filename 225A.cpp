#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, top; cin>>n>>top;
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        int b=7-l,f=7-r;
        if(top==l or top==r or top==f or top==b){
            cout<<"NO"; return 0;
        }
        else top=7-top;
    }
    cout<<"YES";
}