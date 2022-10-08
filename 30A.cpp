#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,n; cin>>A>>B>>n;
    string s="No solution";
    if(A==0){
        if(B==0) cout<<1;
        else cout<<s;
        return 0;
    }
    if(B%A!=0) cout<<s;
    else{
        if(B==0) cout<<0;
        else{
            int X=1;
            while(pow(X,n)<abs(B/A)) X++;
            if(pow(X,n)==abs(B/A) and B/A<0) cout<<'-'<<X;
            else if(pow(X,n)==abs(B/A) and B/A>0) cout<<X;
            else cout<<s;
        }
    }
}