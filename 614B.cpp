#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return 0; }
bool p(string s){
    if(s=="0" or s=="1") return 1;
    if(s[0]!='1') return 0;
    for(int i=1;i<s.length();i++){
        if(s[i]!='0') return 0;
    } return 1;
}
int main(){
    int n,ten=0; cin>>n;
    if(n==1){
        string x; cin>>x; 
        print(x)
    } 
    string ans="1";
    for(int i=0;i<n;i++){
        string t; cin>>t;
        if(t=="0") print(0)
        else if(t=="1") continue;
        else if(p(t)) ten+=t.length()-1;
        else ans=t;
    }
    cout<<ans;
    for(int i=0;i<ten;i++) cout<<'0';
}