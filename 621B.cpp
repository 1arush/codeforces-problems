#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    long long sum=0;
    map<pair<int,int>,int>m;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        m[make_pair(1,y-x)]++;
        m[make_pair(-1,y+x)]++;
    }
    for(auto p:m) sum+=((p.second)*(p.second-1))/2;
    cout<<sum;
}