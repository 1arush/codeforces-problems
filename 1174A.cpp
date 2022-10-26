#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(2*n);
    bool eq=1;
    for(int i=0;i<2*n;i++){
        cin>>v[i];
        if(i!=0 and eq){
            if(v[i]!=v[0]) eq=0;
        }
    }
    if(eq){
        cout<<-1; return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<2*n;i++) cout<<v[i]<<' ';
}