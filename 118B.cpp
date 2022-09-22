#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
void disp(int j, vector<char>v){
    for(int i=1;i<v.size()-2*j;i++) cout<<' ';
    for(int i=0;i<2*j;i++) cout<<v[i]<<' ';
    cout<<v[2*j];
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<char>V(2*n+1);
    vector<vector<char>>T;
    for(int j=0;j<=n;j++){
        for(int i=0;i<j;i++){
            V[i]=char(i+48);
        }
        for(int i=0;i<=j;i++){
            V[j+i]=char(j-i+48);
        }
        disp(j,V); T.push_back(V);
    } T.pop_back();
    for(int i=n-1;i>=0;i--){
        disp(i,T[i]);
    }
    
}