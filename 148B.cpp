#include <bits/stdc++.h>
using namespace std;
int main(){
    double v1,v2,t,f,c; 
    int coin=0;
    cin>>v1>>v2>>t>>f>>c;
    double dist=(v2*v1*t)/(v2-v1);
    if(v1>v2) goto e;
    while(dist<c){
        coin++;
        dist+=v1*(f+dist/v2);
        dist=dist+(dist*v1)/(v2-v1);
    }
e:  cout<<coin;
}