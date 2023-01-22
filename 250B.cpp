#define _CRT_SECURE_NO_WARNINGS

// @author: rushil

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(front) { cout<<front<<'\n'; return; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

string P(string s, int j, int i){
    string ret="";
    ret+=s.substr(j,i-j);
    int g=ret.size();
    forn(k,4-g) ret="0"+ret;
    return ret;
}
string dummy(int n){
    string y="0000:",j="";
    forn(i,n) j+=y;
    return ":"+j;
}
void jiangly(){
    string s; cin>>s;
    if(s=="::") print("0000:0000:0000:0000:0000:0000:0000:0000")
    string res="";
    int i=0,ch=0;
    while(i<s.length()){
        if(s[i]==':'){ res+=s[i++]; continue; }
        int j=i;
        while(i<s.length() && s[i]!=':') i++;
        res+=P(s,j,i);
    }
    forn(i,res.length()){
        if(res[i]!=':') ch++;
    }
    ch=(32-ch)/4; 
    int g=res.find("::");
    string t=dummy(ch);
    if(g==-1) print(res)
    if(g==0){
        t.erase(0,1);
        res=t+res.substr(2,res.length()-2);
    }
    else if(g==res.length()-2){ 
        t.erase(t.length()-1,1);
        res=res.substr(0,res.length()-2)+t;
    }
    else{
        res=res.substr(0,g)+t+res.substr(g+2,res.length()-g-2);
    }
    print(res)
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin>>T;
    while(T--) jiangly();
}