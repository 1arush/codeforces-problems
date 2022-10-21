#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,u=""; cin>>s;
    bool P=0; 
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cout<<"YES\n"<<0; return 0;
        }
        if(s[i]=='8'){
            cout<<"YES\n"<<8; return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int z=j+1;z<n;z++){
                if((s[i]*100+s[j]*10+s[z]-5328)%8==0){
                    u+=s[i]; u+=s[j]; u+=s[z]; P=1;
                    cout<<"YES\n"<<u; return 0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((s[i]*10+s[j]-528)%8==0){
                u+=s[i]; u+=s[j]; P=1;
                cout<<"YES\n"<<u; return 0;
            }
        }
    }
    cout<<"NO";
}