#include <bits/stdc++.h>
using namespace std;
string rev(string s){
    swap(s[0],s[1]);
    return s;
}
int main(){
    int n; cin>>n;
    map<string,int>M;
    while(n>0){
        string noUse;
        string a,b; cin>>a>>b;
        if(n>1) cin>>noUse;
        string s=a+rev(b);
        string T=s+s;
        string P1=T.substr(1,4),P2=T.substr(2,4),P3=T.substr(3,4);
        if(M.find(s)==M.end() && M.find(P1)==M.end() && M.find(P2)==M.end() 
            && M.find(P3)==M.end()){
                M[s]++; n--; continue;
        }
        else if(M.find(s)!=M.end()) M[s]++;
        else if(M.find(P1)!=M.end()) M[P1]++;
        else if(M.find(P2)!=M.end()) M[P2]++;
        else if(M.find(P3)!=M.end()) M[P3]++;

        n--;
    }
    int count=0;
    for(auto pair : M) count++;
    cout<<count<<'\n';
}