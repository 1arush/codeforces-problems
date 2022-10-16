#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    if(s=="4" or s=="8") cout<<4;
    else{
        int L=s.length()-1;
        int N=(s[L-1]-48)*10+(s[L]-48);
        if(N%4==0) cout<<4;
        else cout<<0;
    }
}