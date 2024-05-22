#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int a, b, n, m;
        cin>>a>>b>>n>>m;
        set<pair<int,int>> bx, by;
        for(int i=0; i<n; ++i){
                int x, y;
                cin>>x>>y;
                bx.insert({x,y});
                by.insert({y,x});
        }
        int xu=0, yu=0, xd=0, yd=0;
        // x-xr<=k (remove)
        int alice=0, bob=0;
        for(int q=0; q<m; ++q){
                char tp;
                int k;
                cin>>tp>>k;
                int score=0;
                if(tp=='U'){
                        while(!bx.empty()){
                                auto [x,y]=*bx.begin();
                                if(x-xu<=k){
                                        // cout<<x<<' '<<y<<'\n';
                                        bx.erase({x,y});
                                        by.erase({y,x});
                                        ++score;
                                }else{
                                        break;
                                }
                        }
                        xu+=k;
                }else if(tp=='D'){
                        while(!bx.empty()){
                                auto [x,y]=*prev(bx.end());
                                if((a-x+1)-xd<=k){
                                        // cout<<x<<' '<<(a-x+1)<<'\n';
                                        bx.erase({x,y});
                                        by.erase({y,x});
                                        ++score;
                                }else{
                                        break;
                                }
                        }
                        xd+=k;
                }else if(tp=='L'){
                        while(!by.empty()){
                                auto [y,x]=*by.begin();
                                if(y-yu<=k){
                                        // cout<<x<<' '<<y<<'\n';
                                        bx.erase({x,y});
                                        by.erase({y,x});
                                        ++score;
                                }else{
                                        break;
                                }
                        }
                        yu+=k;
                }else{
                        while(!by.empty()){
                                auto [y,x]=*prev(by.end());
                                if((b-y+1)-yd<=k){
                                        // cout<<x<<' '<<y<<'\n';
                                        bx.erase({x,y});
                                        by.erase({y,x});
                                        ++score;
                                }else{
                                        break;
                                }
                        }
                        yd+=k;
                } 
                if(q&1) bob+=score;
                else alice+=score;
        }
        cout<<alice<<' '<<bob<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int _test=1;
        cin>>_test;
        while(_test--){
                cout<<'\n';
                solve_test();
        }
        return 0;
}
