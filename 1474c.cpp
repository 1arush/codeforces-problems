#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

#ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
#endif

        int _test;
        cin>>_test;
        while(_test--){
                int n;
                cin>>n;
                n*=2;
                vector<int> a(n);
                for(int i=0; i<n; ++i){
                        cin>>a[i];
                }
                sort(a.rbegin(),a.rend());
                bool ok=0;
                for(int i=1; i<n; ++i){
                        int x=a.front()+a[i];
                        multiset<int> ms(a.rbegin(),a.rend());
                        vector<pair<int,int>> vec;
                        bool f=1;
                        while(!ms.empty()){
                                int mx=*prev(ms.end());
                                if(x<=mx){
                                        f=0; break;
                                }
                                ms.erase(ms.find(mx));
                                if(ms.find(x-mx)==ms.end()){
                                        f=0; break;
                                }
                                vec.emplace_back(mx,x-mx);
                                ms.erase(ms.find(x-mx));
                                x=mx;
                        }
                        if(f){
                                cout<<"YES\n";
                                cout<<(a.front()+a[i])<<'\n';
                                for(auto [l,r]:vec){
                                        cout<<l<<' '<<r<<'\n';
                                }
                                ok=1; break;
                        }
                }
                if(!ok){
                        cout<<"NO\n";
                }
        }
        return 0;
}
