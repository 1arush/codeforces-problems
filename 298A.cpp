#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; string s;
    cin>>n>>s;
    int l,r,i=0;
    if(s.find('L')==string::npos){
        while(i<n and s[i]=='.') i++; l=i+1; i=n-1;
        while(i>=0 and s[i]=='.') i--; r=i+2;
        cout<<l<<' '<<r;
        return 0;
    }
    if(s.find('R')==string::npos){
        i=n-1;
        while(i>=0 and s[i]=='.') i--; l=i+1; i=0;
        while(i<n and s[i]=='.') i++; r=i;
        cout<<l<<' '<<r;
        return 0;
    }
    while(i<n and s[i]!='R') i++; l=i+1;
    while(i<n and s[i]=='R') i++; r=i;
    cout<<l<<' '<<r;
}