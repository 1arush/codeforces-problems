#include <bits/stdc++.h>
using namespace std;
string to_excel(int n){
    string s="";
    while(n>0){
        int d;
        if(n%26==0){
            d=26; n=n/26-1;
        }
        else{
            d=n%26; n/=26;
        }
        s+=char('A'-1+d);
    }
    for(int i=0;i<s.length()/2;i++) swap(s[i],s[s.length()-i-1]);
    return s;
}
int from_excel(string s){
    int col=0;
    for(int i=0;i<s.length();i++){
        col*=26;
        col+=int(s[i]-'A'+1);
    }
    return col;
}
int main(){
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        if(s[0]=='R' and s[1]<=57 and s.find("C")!=string::npos){
            int i=1;
            string temp;
            while(s[i]!='C') i++;
            temp=s.substr(1,i-1); i++;
            int Y=0;
            for(i;i<s.length();i++){
                Y*=10;
                Y+=(s[i]-48);
            }
            cout<<to_excel(Y)<<temp<<'\n';
        }
        else{
            int i=0;
            while(s[i]>=65) i++;
            cout<<'R'<<s.substr(i,s.length()-i)<<'C';
            cout<<from_excel(s.substr(0,i))<<'\n';
        }
    }
}