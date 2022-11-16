#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,f=0; char pr;
    cin>>n>>m>>pr;
    vector<string>v(n);
    set<char>s1;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==pr){
                if(i!=0 and v[i-1][j]!=pr) s1.insert(v[i-1][j]);
                if(i!=n-1 and v[i+1][j]!=pr) s1.insert(v[i+1][j]);
                if(j!=0 and v[i][j-1]!=pr) s1.insert(v[i][j-1]);
                if(j!=m-1 and v[i][j+1]!=pr) s1.insert(v[i][j+1]);
            }
        }
    }
    if(s1.find('.')!=s1.end()) f++;
    cout<<s1.size()-f;
}