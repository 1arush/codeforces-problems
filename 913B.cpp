#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x; return 0; }
map<int,vector<int>>tree;
bool isLeaf(int n){
    if(tree.find(n)==tree.end()) return 1;
    return 0;
}
int main(){
    int n,ct=0; cin>>n;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        tree[x].push_back(i);
    }
    for(auto p:tree){
        for(int i=0;i<p.second.size();i++){
            if(!isLeaf(p.second[i])) ct++;
        }
        if(p.second.size()<ct+3) print("No") ct=0;
    }
    print("Yes")
}