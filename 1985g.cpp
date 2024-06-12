#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int M=1e9+7;

int binpow(int x, int n){
        int ret=1;
        while(n){
                if(n&1) ret=(ret*x)%M;
                x=(x*x)%M, n>>=1;
        }
        return ret;
}

void solve_test(){
        int l, r, k;
        cin>>l>>r>>k;
        if(k>9){
                cout<<"0\n"; 
                return;
        }
        // l-digit numbers
        // bound for each digit; k*d<=9 (+ 0)
        int b=1+9/k;
        // how many numbers (r-1 digit) that are made by these b digits
        int ans=binpow(b,r)-binpow(b,l);
        if(ans<0) ans+=M;
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
