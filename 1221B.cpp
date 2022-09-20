#include <iostream>
#include <vector>
using namespace std;
vector<int> notF(vector<int>v){
    vector<int>ret;
    for(int i=0;i<v.size();i++){
        if(v[i]==1) ret.push_back(0);
        else ret.push_back(1);
    }
    return ret;
}
void display(int n){
    if(n==1) cout<<'B'<<"";
    else cout<<'W'<<"";
}
int main(){
    int flag=1;
    int n; cin>>n;
    vector<vector<int>>matrix;
    vector<int>base;
    for(int i=0;i<n;i++) base.push_back(i%2);
    for(int i=0;i<n;i++){
        if(flag==1) matrix.push_back(base);
        else matrix.push_back(notF(base));
        flag*=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) display(matrix[i][j]);
        cout<<'\n';
    }
}