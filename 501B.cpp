#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,string>name;
    map<string,string>revName;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string a,b; cin>>a>>b;
        if(revName.find(a)!=revName.end()){
            string T=revName[a];
            name[T]=b;
            revName.erase(a);
            revName[b]=T;
        }
        else{ 
            name[a]=b; revName[b]=a;
        }
    }
    cout<<name.size()<<'\n';
    for(auto p:name){
        cout<<p.first<<' '<<p.second<<'\n';
    }
}