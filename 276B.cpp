#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    map<char,int>m; // s[i]:frequency
    for(int i=0;i<s.length();i++) m[s[i]]++;
    int odd=0,even=0;
    for(auto P:m){
        if(P.second%2==1) odd++;
        else even++;
    }
    bool win=0;
    int winner=1;
    while(!win){
        winner*=-1;
        if(odd==1) win=1;
        if(odd==0 and even!=0) win=1;
        else{
            if(odd!=1 and even!=0){
                odd++; even--;
            }
            else if(even==0) odd--;
        }
    }
    if(winner==-1) cout<<"First\n";
    else cout<<"Second\n";
}