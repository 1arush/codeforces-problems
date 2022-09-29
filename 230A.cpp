#include <iostream>
using namespace std;
int main(){
    int s,n; cin>>s>>n;
    int x[n],y[n];
    bool T=true;
    for(int i=0;i<n;i++){
        cin>>x[i]; cin>>y[i];
    }
    //sorting
    for(int i=0;i<n;i++){
        int t=i;
        for(int j=i;j<n;j++){
            if(x[j]<x[t])
                t=j;
        }
        int tempo=x[t];
        x[t]=x[i]; x[i]=tempo;
        
        int temp=y[t];
        y[t]=y[i]; y[i]=temp;
    }
    for(int i=0;i<n;i++){
        if(s>x[i]){
            s+=y[i];
        }
        else{
            T=false;
            break;
        }
    }
    if(T==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}