#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v(6);
    int sum=0;
    for(int i=0;i<=5;i++){
        cin>>v[i]; sum+=v[i];
    }
    bool Q=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                int num=v[i]+v[j]+v[k];
                if(num==sum-num){
                    Q=1; goto e;
                }
            }
        }
    }
e:  if(Q) cout<<"Yes";
    else cout<<"No";
}