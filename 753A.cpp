#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int fun(int N){
    int n=1;
    while(n*(n+1)/2<=N){
        if(n*(n+1)/2==N) return n;
        n++;
    }
    return n-1;
}
int main(){
    int n; cin>>n;
    int t=fun(n);
    if(t*(t+1)/2==n){
        cout<<t<<'\n';
        for(int i=1;i<=t;i++) cout<<i<<' ';
        return 0;
    }
    vector<int>v;
    for(int i=1;i<=t;i++) v.push_back(i);
    t=(n-t*(t+1)/2);
    v[v.size()-1]+=t;
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
}