#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define print(x) { cout<<fixed<<setprecision(15)<<x; return 0; }
double z=0.00000000000;
double fact(int n){
    double Z=1;
    while(n>0){
        Z*=n; n--;
    } return Z;
}
int main(){
    string a,b; cin>>a>>b;
    map<char,int>mp1,mp2;
    for(int i=0;i<a.length();i++){
        mp1[a[i]]++; mp2[b[i]]++; 
    }
    int l=min(mp1['+'],mp2['+']),
        r=min(mp1['-'],mp2['-']);
    mp1['+']-=l;  mp2['+']-=l;
    mp1['-']-=r;  mp2['-']-=r;
    if(mp2['-']!=0 or mp2['+']!=0) print(z)
    int a1=mp1['+'], a2=mp1['-'];
    double P=fact(a1+a2)/(fact(a1)*fact(a2)*pow(2,a1+a2));
    print(P)
}