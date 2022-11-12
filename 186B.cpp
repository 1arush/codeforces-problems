#include <bits/stdc++.h>
using namespace std;
#define fs fixed<<setprecision(2)
#define fi first
#define se second
int main(){
    int n; cin>>n;
    vector<pair<double,int>>v;
    double t1,t2,k,i=1; cin>>t1>>t2>>k; 
    k/=100;
    while(i<=n){
        int a,b; cin>>a>>b;
        double h=max(a*t1*(1-k)+b*t2,b*t1*(1-k)+a*t2);
        v.push_back(make_pair(h,i)); i++;
    }
    // Bubble Sort
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()-1;j++){
            if(v[j].fi<v[j+1].fi) swap(v[j],v[j+1]);            
            else if(v[j].fi==v[j+1].fi){
                if(v[j].se>v[j+1].se) swap(v[j],v[j+1]);
            }
        }
    }
    for(int i=0;i<v.size();i++) cout<<v[i].se<<' '<<fs<<v[i].fi<<'\n';
}