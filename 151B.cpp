#include <bits/stdc++.h>
using namespace std;
#define O(v,n) find(v.begin(),v.end(),n)-v.begin()
#define U(n) sort(n.begin(),n.end())
#define fi first
#define se second
#define pb push_back
#define sz size
bool a(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='-' and s[i]!=s[0]) return 0;
    } return 1;
}
bool b(string s){
    int a=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!='-'){
            if(s[i]>=a) return 0;
            else a=s[i];
        }
    } return 1;
}
void disp(vector<string>v){
    for(int i=0;i<v.sz();i++){
        if(i<v.sz()-1) cout<<v[i]<<", ";
        else cout<<v[i]<<'.';
    }
}
int main(){
    int n,T=0,P=0,G=0; cin>>n;
    vector<string>names;
    map<string,int>taxi,pizza,girls;
    for(int i=0;i<n;i++){
        int t; string name;
        cin>>t>>name;
        names.pb(name);
        for(int j=0;j<t;j++){
            string s; cin>>s;
            if(a(s)) taxi[name]++;
            else if(b(s)) pizza[name]++;
            else girls[name]++;
        }
    }
    vector<int>mT,mP,mG;
    for(auto p:taxi) T=max(T,p.se);
    for(auto p:pizza) P=max(P,p.se);
    for(auto p:girls) G=max(G,p.se);
    for(auto p:taxi){
        if(p.se==T){
            int z=O(names,p.fi); mT.pb(z);
        }
    }
    for(auto p:pizza){
        if(p.se==P){
            int z=O(names,p.fi); mP.pb(z);
        }
    }
    for(auto p:girls){
        if(p.se==G){
            int z=O(names,p.fi); mG.pb(z);
        }
    }
    U(mT); U(mP); U(mG);
    cout<<"If you want to call a taxi, you should call: ";
    if(mT.sz()==0) disp(names);
    for(int i=0;i<mT.sz();i++){
        if(i<mT.sz()-1) cout<<names[mT[i]]<<", ";
        else cout<<names[mT[i]]<<".";
    } cout<<'\n';
    cout<<"If you want to order a pizza, you should call: ";
    if(mP.sz()==0) disp(names);
    for(int i=0;i<mP.sz();i++){
        if(i<mP.sz()-1) cout<<names[mP[i]]<<", ";
        else cout<<names[mP[i]]<<".";
    } cout<<'\n';
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    if(mG.sz()==0) disp(names);
    for(int i=0;i<mG.sz();i++){
        if(i<mG.sz()-1) cout<<names[mG[i]]<<", ";
        else cout<<names[mG[i]]<<".";
    } cout<<'\n';
}