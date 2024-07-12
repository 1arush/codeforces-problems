#include <bits/stdc++.h>
#define int int64_t
using namespace std;

#ifndef ONLINE_JUDGE
#define erk(...) cerr<<#__VA_ARGS__<<" = ", vz(__VA_ARGS__)
template<typename T> void vz(vector<T>& x){for(auto i: x) cerr<<i<<' ', cerr<<'\n';}
template<typename T> void vz(T& x){cerr<<x<<'\n';}
template<typename T, typename ...S> void vz(T& x, S&...y){cerr<<x<<", ", vz(y...);}
#else
#define erk(...) 1
#endif

template<typename T> bool ckmin(T &a, T b){return a>b ? a=b,1 : 0;}
template<typename T> bool ckmax(T &a, T b){return a<b ? a=b,1 : 0;}

const int mod=1e9+7, nax=1e5+5;

vector<int> fac(nax), inv(nax), ifac(nax);

void factorial(){
        fac[0]=inv[1]=ifac[0]=1;
        for(int i=1; i<nax; ++i){
                fac[i]=fac[i-1]*i%mod;
                if(i>1) inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
                ifac[i]=ifac[i-1]*inv[i]%mod;
        }
}

int choose(int n, int r){
        if(n<r || n<0 || r<0) return (int)0;
        return fac[n]*ifac[r]%mod*ifac[n-r]%mod;
}

void solve_test(){
        // x is the result of mex(subset,cnt+1)
        // how many such subsets are possible?
        // all the elements in [1,x) can be permuted in some ways
        // answer is summing over all contributions
        
        int n;
        cin>>n;
        int ans=0;
        for(int x=1; x<=n; ++x){
                for(int c=0; c<=n; ++c){
                        int tk=min(n,x-1)-c;
                        ans+=x*choose(x-1,c)%mod*choose(n-x,c-tk)%mod;
                        ans%=mod;
                }
        }
        for(int x=n+1; x<=2*n+1; ++x){
                for(int c=0; c<=n; ++c){
                        if(x==2*c+1){
                                ans+=x*choose(n,c)%mod;
                                ans%=mod;
                        }
                }
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        factorial();
        int t=1;
        cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
