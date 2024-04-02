#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int n,k,cnt;
vector<vector<int>> gr;
vector<int> dp;

void dfs(int u, int p, int x){
        dp[u]=1;
        for(int v:gr[u]){
                if(v==p) continue;
                dfs(v,u,x);
                if(dp[v]>=x){
                        dp[v]=0, cnt++;
                }
                dp[u]+=dp[v];
        }
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                cin>>n>>k;
                gr=vector<vector<int>> (n);
                for(int i=1, u, v; i<n; ++i){
                        cin>>u>>v, --u, --v;
                        gr[u].push_back(v);
                        gr[v].push_back(u);
                }
                int L=0, R=n+1;
                auto good=[&](int x)-> bool {
                        if(n<(k+1)*x) return false;
                        cnt=0;
                        dp=vector<int> (n);
                        dfs(0,-1,x);
                        if(cnt<k) return false;
                        if(cnt>k) return true;
                        return dp[0]>=x ? true : false;
                };
                while(R>L+1){
                        int MID=(L+R)/2;
                        if(good(MID)) L=MID;
                        else R=MID;
                }
                cout<<L<<'\n';
        }
        return 0;
}
