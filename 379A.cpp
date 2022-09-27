#include <iostream>
using namespace std;
int main(){
    int a,b; cin>>a>>b;
    int A=a; int store=a%b;
    while(a/b>0 && (store%b>0 || store==0)){
        A+=a/b+store;
        store=a%b; 
        a/=b;
    }
    cout<<A<<"\n";
}