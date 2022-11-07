#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll r,x1,y1,x2,y2; cin>>r>>x1>>y1>>x2>>y2; r*=2;
    double D=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    ll k=int(D); k/=r;
    if(D-k*r!=0) k++;
    cout<<k;
}