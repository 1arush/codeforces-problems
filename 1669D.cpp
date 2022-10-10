#include <iostream>
#include <string>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;
        int i=0;
        bool isP=1;
        while(i<n){
            if(s[i]!='W'){
                int j=i+1;
                bool distinct=0;
                while(j<n and s[j]!='W'){
                    if(s[j]!=s[i]) distinct=1;
                    j++;
                }
                if(distinct==0){
                    isP=0; break;
                }
                i=j;
            }
            else i++;
        }
        if(isP==1) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
} 