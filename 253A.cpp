#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n,m; cin>>n>>m;
    string s;
    s=(n>=m)?"BG":"GB";
    for(int i=1;i<=min(m,n);i++) cout<<s;
    int end=max(n,m);
    s=(n>=m)?"B":"G";
    for(int i=min(m,n)+1;i<=end;i++) cout<<s;
}