#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(int w=0;w<n;w++){
        cin>>a[w];
    }
    vector<int>even;
    vector<int>odd;
    for(int i=0;i<n;i++){
        if(a[i]%2==0)
            even.push_back(i);
        else
            odd.push_back(i);
    }
    if(even.size()==1){
        cout<<even[0];
    }
    else if(odd.size()==1){
        cout<<odd[0];
    }
}