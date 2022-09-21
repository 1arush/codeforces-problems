#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
string decTo3(int n){
    string s="";
    while(n>0){
        s+=48+n%3;
        n/=3;
    }
    for(int i=0;i<s.length()/2;i++) swap(s[i],s[s.length()-i-1]);
    return s;
}
bool isGood(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='2') return 0;
    }
    return 1;
}
int decRep(string s){
    int n=0;
    for(int i=0;i<s.length();i++){
        n*=3;
        n+=(s[i]-48);
    } return n;
}
int main(){
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        string threeRep=decTo3(n);
        if(isGood(threeRep)){
            cout<<n<<'\n'; continue;
        }
        int l=threeRep.length();
        int first2,first0=-1;
        for(int i=0;i<l;i++){
            if(threeRep[i]=='0') first0=i;
            if(threeRep[i]=='2'){
                first2=i; break;
            }
        }
        // cout<<"first2-"<<first2<<'\n';
        for(int i=first2;i<l;i++) threeRep[i]='0';
        if(first0==-1){
            for(int i=0;i<=first2;i++) threeRep[i]='0';
            threeRep="1"+threeRep;
            cout<<decRep(threeRep)<<'\n'; continue;
        }
        threeRep[first0]='1';
        for(int i=first0+1;i<first2;i++) threeRep[i]='0';
        cout<<decRep(threeRep)<<'\n';
        
    }
}