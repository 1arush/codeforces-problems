#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const string d[10]={"1110111", "0010010", "1011101", "1011011", "0111010",
                    "1101011", "1101111", "1010010", "1111111", "1111011"};

int mask(const string &a, string &b){
        int ret=0;
        for(int i=0; i<7; ++i){
                ret+=(a[i]!=b[i]);
                if(a[i]<b[i]){
                        return 1e9;
                }
        }
        return ret;
}

void solve_test(){
        int n, k;
        cin>>n>>k;
        vector<string> a(n+1);
        for(int i=1; i<=n; ++i){
                cin>>a[i];
        }
        vector<vector<bool>> dp(n+2,vector<bool>(k+1)), to;
        dp[n+1][0]=1;
        for(int i=n; i>0; --i){
                for(int j=0; j<=k; ++j){
                        for(int c=9; c>=0; --c){
                                int p=mask(d[c],a[i]);
                                if(j>=p && dp[i+1][j-p]){
                                        // kind of greedy
                                        dp[i][j]=1;
                                        break;
                                }
                        }
                }
        }       
        if(!dp[1][k]){
                cout<<"-1\n"; 
                return;
        }
        for(int i=1; i<=n; ++i){
                for(int c=9; c>=0; --c){
                        if(k>=mask(d[c],a[i]) && dp[i+1][k-mask(d[c],a[i])]){
                                k-=mask(d[c],a[i]);
                                cout<<c;
                                break;
                        }
                }
        }
        cout<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        // cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
