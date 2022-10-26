#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
int main(){
    double y, x; cin>>y>>x;
    double ans=(x*x-y*y)/(2*y);
    cout<<setprecision(12)<<ans; 
}