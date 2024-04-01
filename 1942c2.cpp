#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                int n,x,y;
                cin>>n>>x>>y;
                vector<int> a(x);
                for(auto &w:a) cin>>w;
                sort(a.begin(),a.end());
                a.push_back(n+a[0]);
                int ans=0;
                vector<int> d;
                for(int i=0; i<x; ++i){
                        int g=abs(a[i]-a[i+1]);
                        if(g==2) ++ans;
                        if(g<3) continue;
                        d.push_back(g);
                }
                auto cmp=[&](int &x, int &y)-> bool {
                        return x%2==y%2 ? x<y : (x%2==0 ? 1 : 0);
                };
                sort(d.begin(),d.end(),cmp);
                int cnt=x;
                for(int i=0; i<(int)d.size() && y>0; ++i){
                        if(d[i]%2){
                                ans+=min(y,d[i]/2);
                                cnt+=min(y,d[i]/2);
                                y-=min(y,d[i]/2);
                        }else{
                                if(y>=d[i]/2-1){
                                        ans+=d[i]/2;
                                        y-=d[i]/2-1;
                                        cnt+=d[i]/2-1;
                                }else{
                                        ans+=y;
                                        cnt+=y;
                                        y=0;
                                }
                        }
                }
                ans+=max(0ll,cnt-2);
                cout<<ans<<'\n';
        }
        return 0;
}
