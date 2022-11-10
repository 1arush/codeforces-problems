#include <bits/stdc++.h>
using namespace std;
#define print(x) { cout<<x<<'\n'; return 0; }
int main(){
    int n,k,sum=0,ans=1e+9,q=0; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        sum+=x;
        v[i]=sum;
    }
    for(int i=0;i+k-1<n;i++){
        if(i==0 and v[i+k-1]<ans){
            ans=v[i+k-1]; q=0;
        }
        else{
            if(v[i+k-1]-v[i-1]<ans){
                ans=v[i+k-1]-v[i-1]; q=i;
            }
        }
    }
    print(++q)
}