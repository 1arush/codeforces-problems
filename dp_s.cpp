#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod=1e9+7;

int n, m, D;
string a, b;

// dp[i][j] - sum i and j is smaller_already

void add_self(int& a, int b){
        a+=b;
        a%=mod;
        a=(a+mod)%mod;
}

int calc(string& s){
        const int n=s.size();
        vector<vector<int>> dp(m,vector<int>(2));
        dp[0][1]=dp[0][0]=1;
        for(int i=n-1; i>=0; --i){
                vector<vector<int>> new_dp(m,vector<int>(2));
                for(int sum=0; sum<m; ++sum){
                        for(int d=0; d<10; ++d){
                                int rem=((sum-d)%m+m)%m;
                                if(d<s[i]-'0'){
                                        add_self(new_dp[sum][1],dp[rem][0]);
                                }
                                if(d==s[i]-'0'){
                                        add_self(new_dp[sum][1],dp[rem][1]);
                                }
                                add_self(new_dp[sum][0],dp[rem][0]);
                        }
                }
                dp=new_dp;
        }
        return (dp[0][1])%mod;
}

void solve_test(){
        cin>>a>>m;
        int ans=calc(a);
        add_self(ans,-1);
        cout<<ans<<'\n';
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
