#include <bits/stdc++.h>
using namespace std;
int main(){
    int d,sum,minS=0,maxS=0; cin>>d>>sum;
    int min[d],max[d];
    for(int i=0;i<d;i++){
        cin>>min[i]>>max[i];
        minS+=min[i]; maxS+=max[i];
    }
    if(minS<=sum && maxS>=sum) cout<<"YES\n";
    else{
        cout<<"NO"; return 0;
    }
    sum-=minS;
    int i=0;
    while(sum>0){
        if(sum>=max[i]-min[i]){
            sum-=(max[i]-min[i]);
            min[i]=max[i];
            i++;
        }
        else{
            min[i]+=sum; sum=0;
        }
    }
    for(int i=0;i<d;i++) cout<<min[i]<<' ';
}