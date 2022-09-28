#include <bits/stdc++.h>
using namespace std;
int main(){
    string xml; cin>>xml;
    int nest=-1;
    for(int i=0;i<xml.length();i++){
        if(xml[i]=='<' and xml[i+1]!='/'){
            nest++;
            for(int j=0;j<2*nest;j++) cout<<' ';
            cout<<xml.substr(i,3)<<'\n';
        }
        else if(xml[i]=='<' and xml[i+1]=='/'){
            for(int j=0;j<2*nest;j++) cout<<' ';
            cout<<xml.substr(i,4)<<'\n';
            nest--;
        }
    }
}