#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    if(s=="9"){
        cout<<9; return 0;
    }
    long long int ans=0;
    for(int i=0;i<s.length();i++){
        if(i==0){
            if(s[i]=='9') continue;
            else if(s[i]-48>=5) s[i]=char(57-(s[i]-48));
        }
        if(s[i]-48>=5) s[i]=char(57-(s[i]-48));
    }
    for(int i=0;i<s.length();i++){
        ans*=10;
        ans+=s[i]-48;
    }
    cout<<ans;
}