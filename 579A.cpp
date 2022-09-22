#include <iostream>
using namespace std;
int hammingWeight(int n) {
        int ans=0;
        int x=1;
        for(int i=1;i<32;i++){
            if(x & n)   ans++;
            x=x<<1;
        }
        if(x & n)   ans++;
        return ans;
}
int main(){
    int n; cin>>n;
    if(n<0){
        cout<<0; return 0;
    }
    int L=hammingWeight(n);
    cout<<L;
}