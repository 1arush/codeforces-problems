#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int ct=0;
    size_t found=s.find('@');
    if (found!=string::npos) ct++;
    if(s[0]=='@' or s.length()<3 or ct<1 or s[s.length()-1]=='@'){
        cout<<"No solution"; return 0;
    }
    vector<string>v;
    for(int i=1;i<s.length()-2;i++){
        if(s[i]=='@'){
            if(s[i+1]=='@' or s[i+2]=='@'){
                cout<<"No solution"; return 0;
            }
        }
    } int I=0,first=0;
    for(int i=1;i<s.length();i++){
        if(s[i]=='@'){
            if(first==0){
                I=i-2; first=1;
            }
            int j=i+3;
            for(j;j<s.length();j++){
                if(s[j]=='@') break;
            }
            if(j==s.length()) v.push_back(s.substr(i-1,j-i+1));
            else v.push_back(s.substr(i-1,j-i));
        }
    }
    cout<<s.substr(0,I+1);
    for(int i=0;i<v.size()-1;i++) cout<<v[i]<<',';
    cout<<v[v.size()-1];
}