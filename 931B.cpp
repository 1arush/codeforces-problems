#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,count=0; cin>>n>>a>>b;
    string s=""; 
    int level=int(log2(n));
    bool shouldI=0; 
    for(int i=0;i<n;i++){
        if(i==a-1 or i==b-1) s+='1';
        else s+='0';
    }
    while(count<level and !shouldI){
        count++; 
        string z="";
        for(int i=0;i<s.length()-1;i+=2){
            if(s[i]=='1' and s[i+1]=='1'){
                shouldI=1; break;
            }
            else z+=max(s[i],s[i+1]);
        } 
        s=z;
    }
    if(count==level) cout<<"Final!";
    else cout<<count;
}