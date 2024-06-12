#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n, m, t;
vector<vector<char>> grid;
vector<vector<int>> dsu, vis;

bool outside(int x, int y){
        return x>=n || y>=m || x<0 || y<0;
}

void dfs(int x, int y){
        vis[x][y]=1;
        dsu[x][y]=t;
        for(int dx=-1; dx<2; ++dx){
                for(int dy=-1; dy<2; ++dy){
                        if(abs(dx)+abs(dy)!=1 || outside(x+dx,y+dy)) continue;
                        if(!vis[x+dx][y+dy] && grid[x+dx][y+dy]=='#') dfs(x+dx,y+dy);
                }
        }
}

void solve_test(){
        cin>>n>>m;        
        t=0;
        grid=vector<vector<char>>(n,vector<char>(m));
        dsu=vector<vector<int>>(n,vector<int>(m));
        vis=vector<vector<int>>(n,vector<int>(m));
        for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                        cin>>grid[i][j];
                }
        }
        for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                        if(!vis[i][j] && grid[i][j]=='#'){
                                t++;
                                dfs(i,j);
                        }
                }
        }
        vector<int> cnt(n*m+2), seen(n*m+2);
        for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                        if(grid[i][j]=='#'){
                                cnt[dsu[i][j]]++;
                        }
                }
        }
        int ans=0;
        // rows
        for(int i=0; i<n; ++i){
                int c=0;
                queue<int> q;
                for(int j=0; j<m; ++j){
                        if(grid[i][j]=='.') c++;
                        else{
                                if(!seen[dsu[i][j]]){
                                        c+=cnt[dsu[i][j]];
                                        q.push(dsu[i][j]);
                                        seen[dsu[i][j]]=1;
                                }
                        }
                        if(i-1>=0 && grid[i-1][j]=='#' && !seen[dsu[i-1][j]]){
                                c+=cnt[dsu[i-1][j]];
                                q.push(dsu[i-1][j]);
                                seen[dsu[i-1][j]]=1;
                        }
                        if(i+1<n && grid[i+1][j]=='#' && !seen[dsu[i+1][j]]){
                                c+=cnt[dsu[i+1][j]];
                                q.push(dsu[i+1][j]);
                                seen[dsu[i+1][j]]=1;
                        }
                }
                while(!q.empty()){
                        int x=q.front();
                        q.pop();
                        seen[x]=0;
                }
                ans=max(ans,c);
        }
        // columns
        for(int j=0; j<m; ++j){
                int c=0;
                queue<int> q;
                for(int i=0; i<n; ++i){
                        if(grid[i][j]=='.') c++;
                        else{
                                if(!seen[dsu[i][j]]){
                                        c+=cnt[dsu[i][j]];
                                        q.push(dsu[i][j]);
                                        seen[dsu[i][j]]=1;
                                }
                        }
                        if(j-1>=0 && grid[i][j-1]=='#' && !seen[dsu[i][j-1]]){
                                c+=cnt[dsu[i][j-1]];
                                q.push(dsu[i][j-1]);
                                seen[dsu[i][j-1]]=1;
                        }
                        if(j+1<m && grid[i][j+1]=='#' && !seen[dsu[i][j+1]]){
                                c+=cnt[dsu[i][j+1]];
                                q.push(dsu[i][j+1]);
                                seen[dsu[i][j+1]]=1;
                        }
                }
                while(!q.empty()){
                        int x=q.front();
                        q.pop();
                        seen[x]=0;
                }
                ans=max(ans,c);
        }
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
