#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int x=0,y=0,z=0;
    for(int q=0;q<n;q++){
        int a,b,c;
        cin>>a>>b>>c;
        x+=a; y+=b; z+=c;
    }
    
    if(x==0 && y==0 && z==0)
        cout<<"YES";
    else
        cout<<"NO";
    
}