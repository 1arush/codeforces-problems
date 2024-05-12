// dp[i][j][s] = # of ways to be at cabin j on day i using path length 's'
// s=0 -> short, else -> long
// dp[i][j][0] = sum over t dp[i-1][t][0]*s[t] + dp[i-1][t][1]*l[t]
// dp[i][j][1] = sum over t dp[i-1][t][0]*s[t]
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD=1e9+7;

vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b){
        const int m=a.size();
        // O(m^3)
        vector<vector<int>> ans(m,vector<int>(m));
        for(int i=0; i<m; ++i){
                for(int j=0; j<m; ++j){
                        for(int k=0; k<m; ++k){
                                ans[i][j]+=a[i][k]*b[k][j];
                                ans[i][j]%=MOD;
                        }
                }
        }
        return ans;
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int m, n;
        cin>>m>>n;
        vector<int> dp(m);
        dp[0]=1;
        vector<int> s(m), l(m);
        for(int i=0; i<m; ++i){
                cin>>s[i];
        }
        for(int i=0; i<m; ++i){
                cin>>l[i];
        }
        vector<vector<int>> M(m,vector<int>(m)), res(m,vector<int>(m));
        for(int i=0; i<m; ++i){
                for(int j=0; j<m; ++j){
                        int v=(s[i]+l[i])*(s[j]+l[j])%MOD-l[i]*l[j]%MOD;
                        M[i][j]=(v+MOD)%MOD;
                }
                res[i][i]=1;
        }
        while(n){
                if(n&1) res=matmul(res,M);
                n>>=1;
                M=matmul(M,M);
        }
        int ans=0;
        for(int i=0; i<m; ++i){
                for(int j=0; j<m; ++j){
                        ans+=res[i][j]*dp[j]%MOD;
                        ans%=MOD;
                }
                cout<<'\n';
        }
        cout<<ans<<'\n';
        return 0;       
}
