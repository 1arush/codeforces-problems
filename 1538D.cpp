#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
const int N=1e5+1;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        int a,b,k;
        cin>>a>>b>>k;
        int p=a, q=b;
        int _max=0;
        while(a%2==0){
            _max++, a/=2;
        }
        while(b%2==0){
            _max++, b/=2;
        }
        for(int i=3; i*i<=max(a,b); i+=2){
            while(a%i==0){
                _max++, a/=i;
            }
            while(b%i==0){
                _max++, b/=i;
            }
        }
        if(a>1) _max++;
        if(b>1) _max++;
        int _min=2;
        if(p==q) _min=0;
        else if(p%q==0 || q%p==0) _min=1;
        bool ok=false;
        if(k==1 && _min==1 && k<=_max) ok=true;
        else if(k<=_max && k>=_min && k!=1) ok=true;
        cout<<((ok) ? "YES" : "NO");
        cout<<'\n';
    }
    return 0;
}