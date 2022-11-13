#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,gcd; cin>>a>>b>>c>>d;
    if(a*d>b*c){
        int p=a*d-b*c,q=a*d;
        gcd=__gcd(p,q);
        cout<<p/gcd<<'/'<<q/gcd;
    }
    else{
        if(a*d==b*c) cout<<"0/1";
        else{
            int p=b*c-a*d,q=b*c;
            gcd=__gcd(p,q);
            cout<<p/gcd<<'/'<<q/gcd;
        }
    }
}