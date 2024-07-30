#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> gr;
vector<int> a, lf, dp;

void dfs(int i){
        if(gr[i].empty()){
                lf[i]=dp[i]=1; return;
        }
        for(int v:gr[i]){
                dfs(v);
                lf[i]+=lf[v];
        }
        if(!a[i]) dp[i]=1;
        for(int v:gr[i]){
                if(!a[i]){
                        dp[i]+=dp[v]-1;
                }else{ 
                        // sum of leaves - sum_lf + dp[v]
                        dp[i]=max(dp[i],lf[i]-lf[v]+dp[v]);
                }
        }
}

void solve_test(){
        int n;
        cin>>n;
        gr=vector<vector<int>> (n);
        lf=vector<int> (n);
        dp=vector<int> (n);
        a=vector<int> (n);
        for(int i=0; i<n; ++i){
                cin>>a[i];
        }                
        for(int i=1, p; i<n; ++i){
                cin>>p, --p;
                gr[p].push_back(i);
        }
        dfs(0);
        cout<<dp[0]<<'\n';
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
