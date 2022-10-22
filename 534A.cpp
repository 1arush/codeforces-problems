#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    if(n==1 or n==2){
        cout<<"1\n1"; return 0;
    }
    if(n==3){
        cout<<"2\n1 3"; return 0;
    }
    if(n==4){
        cout<<"4\n3 1 4 2"; return 0;
    }
    cout<<n<<"\n";
    int a=1,b;
    if(n%2==0) b=n/2+1;
    else b=n/2+2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout<<a<<' '; a++;
        }
        else{
            cout<<b<<' '; b++;
        }
    }
}