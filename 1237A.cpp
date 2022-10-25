#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    bool up=1;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        if(t%2==0) cout<<t/2<<"\n";
        else{
            if(up){
                if(t>0) cout<<t/2+1<<'\n';
                else cout<<t/2<<'\n';
            }
            else{
                if(t>0) cout<<t/2<<'\n';
                else cout<<t/2-1<<'\n';
            }
            up=!up;
        }
    }
}