#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main(){
    int n,m,k; cin>>n;
    double maxX=0,maxY=0,minZ=5000;
    vector<double>x,y,z;
    for(int i=0;i<n;i++){
        double q; cin>>q;
        if(q>maxX) maxX=q;
        x.push_back(q);
    } cin>>m;
    for(int i=0;i<m;i++){
        double q; cin>>q;
        if(q>maxY) maxY=q;
        y.push_back(q);
    } cin>>k;
    for(int i=0;i<k;i++){
        double q; cin>>q;
        if(q<minZ) minZ=q;
        z.push_back(q);
    }
    double A,B; cin>>A>>B;
    double exp=sqrt((B*maxY)/(A*minZ+B*maxY));
    exp*=maxX;
    cout<<fixed<<setprecision(15)<<exp;
}