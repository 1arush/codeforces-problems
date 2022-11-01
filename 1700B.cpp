#include <bits/stdc++.h>
using namespace std;
string sub(string str1, string str2){
    string str="";
    int n1=str1.length(), n2=str2.length();
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int carry=0;
    for(int i=0;i<n2;i++){ 
        int sub=((str1[i]-'0')-(str2[i]-'0')-carry);
        if(sub<0){
            sub=sub+10;
            carry=1;
        }
        else carry=0;
        str.push_back(sub+'0');
    } 
    for(int i=n2;i<n1;i++){
        int sub=((str1[i]-'0')-carry);
        if(sub<0){
            sub=sub+10;
            carry=1;
        }
        else carry=0;
        str.push_back(sub+'0');
    }
    reverse(str.begin(),str.end());
    return str;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; string s; 
        cin>>n>>s;
        if(s[0]!='9'){
            for(int i=0;i<s.length();i++) s[i]=char(105-s[i]);
            cout<<s<<'\n'; continue;
        }
        string big="";
        for(int i=0;i<=s.length();i++) big+='1';
        string N=sub(big,s);
        N=N.substr(1,N.length()-1);
        cout<<N<<'\n';
    }
}