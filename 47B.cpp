#include <bits/stdc++.h>
using namespace std;
#define i insert
string F(string s){
    if(s[1]=='>'){
        s[1]='<'; swap(s[0],s[2]);
    } 
    return s;
}
int main(){
    string x,y,z; cin>>x>>y>>z;
    char lo,mi,hi='0';
    x=F(x); 
    y=F(y);
    z=F(z);
    set<char>st;
    if(x[2]==y[2] or x[2]==z[2]) hi=x[2];
    else if(y[2]==z[2]) hi=y[2];
    if(hi=='0'){ 
        cout<<"Impossible"; return 0;
    }
    if(z[2]!=hi){
        mi=z[2]; lo=z[0]; 
    }
    else if(x[2]!=hi){
        mi=x[2]; lo=x[0]; 
    }
    else{
        mi=y[2]; lo=y[0]; 
    }
    st.i(lo); 
    st.i(mi); 
    st.i(hi);
    if(st.size()<3) cout<<"Impossible";
    else cout<<lo<<mi<<hi;
}