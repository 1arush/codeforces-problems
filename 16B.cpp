#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define s second
#define f first
int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m/2;i++) swap(v[i],v[m-i-1]);
    ll sum=0;
    for(int i=0;i<m;i++){
        if(n>0){
            if(n>=v[i].s){
                sum+=v[i].s*v[i].f; n-=v[i].s;
            }
            else{
                sum+=v[i].f*n; n=0;
            }
        }
        else break;
    }
    cout<<sum;
}