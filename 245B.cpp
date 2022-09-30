#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int i=0;
    if(s[0]=='h'){
        cout<<"http://"<<""; i+=4;
    }
    else{
        cout<<"ftp://"<<""; i+=3;
    } int R=s.length()-1;
    for(R;R>=i+1;R--){
        if(s[R]=='u' and s[R-1]=='r'){
            break;
        }
    } R--; // index of 'r'
    bool P=0,Q=0; // if only 1 'ru'
    if(R==i) P=1;
    if(R==s.length()-2) Q=1;
    for(int t=i;t<R;t++) cout<<s[t]<<"";
    if(!P) cout<<".";
    cout<<"ru";
    for(int t=R+2;t<s.length();t++){
        if(t==R+2) cout<<"/";
        cout<<s[t];
    }
}