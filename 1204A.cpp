#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    bool x=1;
    for(int i=1;i<s.length();i++){
        if(s[i]!='0'){
            x=0; break;
        }
    }
    int ct=(s.length()%2==0)?s.length()/2:(s.length()+1)/2;
    if(x and s.length()%2==0) cout<<ct;
    else if(x) cout<<ct-1;
    else cout<<ct;
}