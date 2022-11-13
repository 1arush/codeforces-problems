#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; continue; }
vector<string>A {"Carrots","Kiwis","Grapes"};
int main(){
    int n,m,k,t; cin>>n>>m>>k>>t;
    vector<int>v;
    for(int i=0;i<k;i++){
        int x,y; cin>>x>>y;
        v.push_back((x-1)*m+y);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<t;i++){
        int p,q; cin>>p>>q;
        int y=(p-1)*m+q;
        int it=lower_bound(v.begin(),v.end(),y)-v.begin();
        if(v[it]==y) print("Waste")
        y=y-it;
        print(A[(y+2)%3])
    }
}