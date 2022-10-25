#include <bits/stdc++.h>
using namespace std;
#define o(n) n/2+n%2
int main(){
    int n; cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x; mp[x]++;
    }
    int maxi=0;
    for(auto P : mp){
        if(P.second>maxi) maxi=P.second;
    }
    string s=(maxi<=o(n))?"YES":"NO";
    cout<<s;
}