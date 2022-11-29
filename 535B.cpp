#include <bits/stdc++.h>
using namespace std;
void Q(int &n, string s, int L=1){
    for(int i=s.length()-1;i>=0;i--){
        n+=L*(s[i]-48+1); L*=2;
    }
}
int main(){
    string s; cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='7') s[i]='1';
        else s[i]='0';
    }
    int i=0; Q(i,s);
    cout<<i;
}