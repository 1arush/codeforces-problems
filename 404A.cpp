#include <bits/stdc++.h>
using namespace std;
bool fun(vector<string>v, int a, int b){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i or j==n-i-1){
                if(v[i][j]!=a) return 0;
            }
            else{
                if(v[i][j]!=b) return 0;
            }
        } 
    }
    return 1;
}
int main(){
    int n; cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    char a=v[0][0],b=v[0][1];
    if(a==b){
        cout<<"NO"; return 0;
    }
    string s=(fun(v, a, b))?"YES":"NO";
    cout<<s;
}