#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
using namespace std;
#define pi 3.141592653
int main(){
    int n; cin>>n;
    vector<double>v;
    for(int i=0;i<n;i++){
        double x,y; cin>>setprecision(12)>>x>>y;
        double ang=(180*(atan2(y,x))/pi);
        v.push_back(ang);
    }
    sort(v.begin(),v.end());
    v.push_back(360+v.front());
    double q=1e-12;
    for(int i=0;i<n;i++) q=max(q,v[i+1]-v[i]);
    cout<<setprecision(12)<<360.00-q;
}