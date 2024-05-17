#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int _test;
        cin>>_test;
        while(_test--){
                int n;
                cin>>n;
                vector<int> a(n), b;
                for(int i=0; i<n; ++i){
                        cin>>a[i];
                }
                auto solve=[&]()-> bool {
                        b=a;
                        vector<pair<int,int>> u, v;
                        for(int i=0; i<n; ++i){
                                if(i&1 && i<n-2){
                                        u.emplace_back(a[i],i);
                                }else{
                                        v.emplace_back(a[i],i);
                                }
                        }
                        sort(u.begin(),u.end());
                        sort(v.begin(),v.end());
                        int nxt=n;
                        for(auto [x,in]:u){
                                b[in]=nxt--;
                        }
                        for(auto [x,in]:v){
                                b[in]=nxt--;
                        }
                        for(int i=1; i<n-1; ++i){
                                if(!(i&1)) continue;
                                if(a[i]+b[i]<=a[i-1]+b[i-1] || a[i]+b[i]<=a[i+1]+b[i+1]) return 0;
                        }
                        return 1;
                };
                if(solve()){
                        for(int x:b){
                                cout<<x<<' ';
                        }
                        cout<<'\n';
                        continue;
                }
                reverse(a.begin(),a.end());
                solve();
                reverse(b.begin(),b.end());
                for(int x:b){
                        cout<<x<<' ';
                }
                cout<<'\n';
        }
        return 0;
}
