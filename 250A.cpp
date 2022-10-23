#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, neg=0; cin>>n;
    vector<int>v;
    bool s=1;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
        if(x!=0 and s) s=0;
        if(x<0) neg++;
    }
    int f=neg/2+neg%2;
    if(s==1 or f==0 or f==1){
        cout<<"1\n"<<n; return 0;
    }
    cout<<f<<'\n';
    int k=0, i=0, cnt=0; neg=0;
    for(i;i<n;i++){
        if(k==f-1) break;
        if(v[i]<0){
            neg++; cnt++;
        }
        else cnt++;
        if(neg==2){
            k++; cout<<cnt<<' '; neg=0; cnt=0;
        }
    }
    cout<<n-i;
}