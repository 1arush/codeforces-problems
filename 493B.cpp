#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    long long int sumA=0,sumB=0;
    vector<int> a,b; string last;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x>0){
            if(i==n-1) last="first";
            sumA+=x; a.push_back(x);
        }
        else{
            if(i==n-1) last="second";
            sumB-=x; b.push_back(-x);
        }
    }
    if(sumA>sumB) cout<<"first";
    else if(sumA<sumB) cout<<"second";
    else{
        if(a==b) cout<<last;
        else if(a<b) cout<<"second";
        else cout<<"first";
    }
}