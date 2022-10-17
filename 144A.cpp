#include <bits/stdc++.h>
using namespace std;
int f(vector<int>&v, int maxi){
    int ct=0,mini=v.size()-1;
    if(maxi==0) goto L;
    for(int i=maxi;i>0;i--){
        swap(v[i],v[i-1]); ct++;
    }
L:  for(int i=v.size()-1;i>=0;i--){
        if(v[i]<v[mini]) mini=i;
    }
    if(mini==v.size()-1){
        if(ct==0) return 0;
        else return ct;
    }
    for(int i=mini;i<v.size()-1;i++){
        swap(v[i],v[i+1]); ct++;
    }
    return ct;
}
int main(){
    int n; cin>>n;
    vector<int>v(n);
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>v[maxi]) maxi=i;
    }
    cout<<f(v,maxi);
}