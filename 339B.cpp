#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m; cin>>n>>m;
    vector<int>v;
    for(int i=0;i<m;i++){
        long long temp; cin>>temp;
        v.push_back(temp);
    }
    long long s=v[0]-1;
    for(int i=0;i<m-1;i++){
        if(v[i]<=v[i+1]){
            s+=v[i+1]-v[i];
        }
        else{
            s+=n+(v[i+1]-v[i]);
        }
        //cout<<s<<" ";
    }
    cout<<s;
}