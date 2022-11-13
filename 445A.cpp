#include <bits/stdc++.h>
using namespace std;
vector<char>w={'B','W'};
int main(){
    int n,m; cin>>n>>m;
    vector<string>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.') v[i][j]=w[(i+j)%2];
        }
    }
    for(int i=0;i<n;i++) cout<<v[i]<<'\n';
}