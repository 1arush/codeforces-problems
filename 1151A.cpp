#include <bits/stdc++.h>
using namespace std;
string ge="ACTG";
int mex(string s){
    int M=0;
    for(int i=0;i<4;i++){
        int path=min(abs(s[i]-ge[i]),26-s[i]+ge[i]);
        M+=min(path,26-ge[i]+s[i]);
    }
    return M;
}
int main(){
    int n,ct=1e+6; cin>>n;
    string s; cin>>s;
    for(int i=0;i<s.length()-3;i++) ct=min(ct,mex(s.substr(i,4)));
    cout<<ct;
}