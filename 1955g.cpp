#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MXN=104;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};

int a[MXN][MXN], vis[MXN][MXN], n, m;

bool inside(int x, int y){
        return x>=1 && y>=1 && x<=n && y<=m;
}

void dfs(int u, int v, int g){
        if(vis[u][v] || a[u][v]%g) return;
        vis[u][v]=1;
        int nx=u+1, ny=v;
        if(inside(nx,ny) && !vis[nx][ny] && a[nx][ny]%g==0) dfs(nx,ny,g);
        nx=u, ny=v+1;
        if(inside(nx,ny) && !vis[nx][ny] && a[nx][ny]%g==0) dfs(nx,ny,g);
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
                cin>>n>>m;
                for(int i=1; i<=n; ++i){
                        for(int j=1; j<=m; ++j){
                                cin>>a[i][j];
                        }
                }
                vector<int> can;
                int z=__gcd(a[1][1],a[n][m]);
                for(int i=1; i*i<=z; ++i){
                        if(z%i==0){
                                can.push_back(i);
                                if(i*i!=z) can.push_back(z/i);
                        }
                }       
                sort(can.rbegin(),can.rend());
                for(int val:can){
                        for(int i=0; i<=n; ++i){
                                for(int j=0; j<=m; ++j) vis[i][j]=0;
                        }                        
                        dfs(1,1,val);
                        if(vis[n][m]){
                                cout<<val<<'\n';
                                break;
                        }
                }
        }
        return 0;
}
