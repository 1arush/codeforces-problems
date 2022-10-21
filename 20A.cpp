#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    string fin="";
    int i=0;
    while(i<s.length()){
        if(s[i]!='/'){
            fin+=s[i]; i++; continue;
        }
        int j=i;
        for(j;j<s.length();j++){
            if(s[j]=='/') continue;
            else break;
        }
        fin+='/';
        i=j;
    }
    if(fin.length()>1 and fin[0]=='/' and fin[1]!='/'){
        if(fin[fin.length()-1]=='/')
            fin.erase(fin.length()-1,1);
    }
    cout<<fin;
}