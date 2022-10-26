#include <bits/stdc++.h>
using namespace std;
#define u .length()
int main(){
    string s, d, l="", r=""; cin>>s>>d;
    int i=0;
    while(i<s u and s[i]!='|'){
        l+=s[i]; i++;
    } i++;
    while(i<s u){
        r+=s[i]; i++;
    } i=0;
    while(i<d u){
        if(l u<r u) l+=d[i];
        else r+=d[i];
        i++;
    }
    if(l u!=r u){
        cout<<"Impossible"; return 0;
    }
    else cout<<l<<'|'<<r;
}