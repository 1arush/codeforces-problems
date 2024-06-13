#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int M=1e9+7, MXN=1050000;

vector<int> lp (MXN), fac(MXN), inv(MXN), ifac(MXN);

void sieve(){
        lp[1]=1;
        for(int i=2; i<MXN; ++i){
                if(lp[i]==0){
                        lp[i]=i;
                }
                for(int j=2*i; j<MXN; j+=i){
                        lp[j]=(lp[j]==0 ? i : min(lp[j],i));
                }
        }
}

void factorial(){
        fac[1]=inv[1]=ifac[1]=1;
        for(int i=2; i<MXN; ++i){
                fac[i]=fac[i-1]*i%M;
                inv[i]=(M-(M/i)*inv[M%i]%M)%M;
                ifac[i]=ifac[i-1]*inv[i]%M;
        }
}

int C(int n, int r){
        if(n==r) return (int)1;
        return fac[n]*ifac[r]%M*ifac[n-r]%M;
}

int binpow(int x, int n){
        int ret=1;
        while(n){
                if(n&1) ret=ret*x%M;
                x=x*x%M, n>>=1;
        }
        return ret;
}

void solve_test(){
        int x, y;
        cin>>x>>y;
        vector<pair<int,int>> vec;
        while(x>1){
                int d=lp[x], cnt=0;
                while(x%d==0){
                        x/=d, ++cnt;
                }
                vec.emplace_back(d,cnt);
        }
        int ans=binpow(2,y-1);
        for(auto [p,f]:vec){
                ans=ans*C(y+f-1,f)%M;
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        sieve();
        factorial();
        int t=1;
        cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
