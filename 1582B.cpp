#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ul;
using namespace std;
ul powOf2(ul n){
    return pow(2,n);
}
int main()
{
    int t; cin>>t;
    while(t--){
        ul n; cin>>n;
        vector<int>v;
        int n1=0,n0=0;
        for(int i=0;i<n;i++){
            int y; cin>>y; v.push_back(y);
            if(y==1)    n1++;
            else if(y==0)   n0++;
        }
        cout<<n1*powOf2(n0)<<endl;
    }
}