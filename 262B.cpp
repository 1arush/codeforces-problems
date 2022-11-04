#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,k,les=0,sum=0; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<=0) les++;
    }
    if(les==0){
        k=k%2;
        if(k) v[0]*=-1; goto L;
    }
    for(int i=0;i<les;i++){
        if(k==0) goto L;
        v[i]*=-1; k--;
    }
    k=k%2;
    if(k){
        if(les<n){
            if(abs(v[les-1])<abs(v[les])) v[les-1]*=-1;
            else v[les]*=-1;
        }
        else v[les-1]*=-1;
    }
L:  for(int i=0;i<n;i++) sum+=v[i];
    cout<<sum;
}