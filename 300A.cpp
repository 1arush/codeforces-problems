#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pq pop_back
int main(){
    int n; cin>>n;
    vector<int> v(n),po,ne,z;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        if(v[i]==0) z.pb(v[i]);
        else if(v[i]<0) ne.pb(v[i]);
        else po.pb(v[i]);
    }
    if(ne.size()%2==0){
        z.pb(ne.back());
        ne.pq();
    }
    if(po.size()==0 and ne.size()>=3){
        po.pb(ne.back()); ne.pq();
        po.pb(ne.back()); ne.pq();
    }
    cout<<ne.size()<<' ';
    for(int i=0;i<ne.size();i++) cout<<ne[i]<<' '; 
    cout<<endl<<po.size()<<' ';
    for(int i=0;i<po.size();i++) cout<<po[i]<<' '; 
    cout<<endl<<z.size()<<' ';
    for(int i=0;i<z.size();i++) cout<<z[i]<<' ';
    
    
    return 0;
}