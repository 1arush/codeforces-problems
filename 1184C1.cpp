#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int row[51]={0},col[51]={0};
    vector<int>v;
    for(int i=0;i<4*n+1;i++){
        int x,y; cin>>x>>y;
        v.push_back(x); v.push_back(y);
        row[x]++; col[y]++;
    }
    int left,right,top,bottom;
    for(int i=0;i<51;i++){
        if(row[i]>=n){
            top=i; break;
        }
    }
    for(int i=50;i>=0;i--){
        if(row[i]>=n){
            bottom=i; break;
        }
    }
    for(int i=0;i<51;i++){
        if(col[i]>=n){
            left=i; break;
        }
    }
    for(int i=50;i>=0;i--){
        if(col[i]>=n){
            right=i; break;
        }
    }
    for(int i=0;i<=v.size()-2;i+=2){
        if(v[i]==top and (v[i+1]<left or v[i+1]>right)){
            cout<<v[i]<<' '<<v[i+1]; return 0;
        }
        else if(v[i]==bottom and (v[i+1]<left or v[i+1]>right)){
            cout<<v[i]<<' '<<v[i+1]; return 0;
        }
        else if(v[i+1]==left and (v[i]>bottom or v[i]<top)){
            cout<<v[i]<<' '<<v[i+1]; return 0;
        }
        else if(v[i+1]==right and (v[i]>bottom or v[i]<top)){
            cout<<v[i]<<' '<<v[i+1]; return 0;
        }
        if(v[i]==top or v[i]==bottom or v[i+1]==left or v[i+1]==right){
            continue;
        }
        else{
            cout<<v[i]<<' '<<v[i+1]; return 0;
        }
    }
}