#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; string s; 
    cin>>n>>s;
    if(n==2 or n==3){
        cout<<s; return 0;
    } int i=0;
    if(n%2==0){
        while(i<=n-4){
            cout<<s[i]<<s[i+1]<<'-'; i+=2;
        }
        cout<<s[i]<<s[i+1];
    }
    else{
        while(i<=n-5){
            cout<<s[i]<<s[i+1]<<'-'; i+=2;
        }
        cout<<s[i]<<s[i+1]<<s[i+2];
    }
}