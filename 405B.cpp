#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ct=0; string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='.') ct++;
        if(s[i]=='L') ct=0;
        if(s[i]=='R'){
            int j=i;
            while(j<n && s[j]!='L') j++;
            if(j==n) break;
            if(j-i-1 & 1) ct++; i=j;
        }
    }
    cout<<ct;
}