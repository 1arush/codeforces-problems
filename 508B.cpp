#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x; return 0; }
int main(){
    string s; cin>>s;
    char a=s[s.length()-1];
    vector<int>v;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]%2==0) v.push_back(i);
    }
    if(v.size()==0) print(-1)
    for(int i=0;i<v.size();i++){
        if(s[v[i]]<a){
            swap(s[v[i]],s[s.length()-1]); print(s)
        }
    }
    swap(s[v[v.size()-1]],s[s.length()-1]);
    print(s)
}