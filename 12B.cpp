#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,guess,answer=""; cin>>s>>guess;
    if(s=="0" and guess=="0"){
        cout<<"OK"; return 0;
    }
    sort(s.begin(),s.end());
    int i=0;
    for(i;i<s.length();i++){
        if(s[i]!='0') break;
    } answer+=s[i];
    for(int j=0;j<i;j++) answer+=s[j];
    for(int w=i+1;w<s.length();w++) answer+=s[w];
    if(answer==guess) cout<<"OK";
    else cout<<"WRONG_ANSWER";
}