#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    vector<int>v;
    set<int>s1;
    int i=0;
    while(i<s.length()){
        int j=i+1;
        while(j<s.length()){
            if(s[j]==',') break; j++;
        }
        s1.insert(stoi(s.substr(i,j-i)));
        i=j+1;
    }
    for(auto it=s1.begin();it!=s1.end();++it) v.push_back(*it);
    // for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    int a=0,n=v.size();
    while(a<n){
        int b=a+1;
        for(b;b<n;b++){
            if(v[b]-v[b-1]!=1) break;
        }
        if(a==b-1 and b!=n) cout<<v[a]<<',';
        else if(a==b-1 and b==n) cout<<v[a];
        else if(a!=b-1 and b!=n) cout<<v[a]<<'-'<<v[b-1]<<',';
        else cout<<v[a]<<'-'<<v[b-1];
        a=b;
    }

}