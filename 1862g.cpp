// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n), v;
        multiset<int> ms, d;
        for(auto &x:a){
            cin>>x;
            ms.insert(x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(int i=0; i+1<(int)v.size(); ++i) d.insert(v[i+1]-v[i]);
        v.clear();
        int q;
        cin>>q;
        while(q--){
            int i,x;
            cin>>i>>x, --i;
            int v=a[i];
            a[i]=x;
            if(n==1){
                ms.erase(ms.find(v));
                ms.insert(x);
                cout<<x<<' '; continue;
            }
            auto it=ms.lower_bound(v);
            // remove a[i]
            if(it==ms.begin() && ms.size()>=2){
                auto pt=next(it);
                d.erase(d.find(*pt-*it));
            }
            else if(next(it)==ms.end() && ms.size()>=2){
                auto pt=prev(it);
                d.erase(d.find(*it-*pt));
            }
            else if(ms.size()>1){
                auto pt=prev(it), nt=next(it);
                d.erase(d.find(*it-*pt));
                d.erase(d.find(*nt-*it));
                d.insert(*nt-*pt);
            }
            ms.erase(ms.find(v));
            // add x
            it=ms.upper_bound(x);
            if(it==ms.end()){
                d.insert(x-*prev(ms.end()));
            }
            else if(it==ms.begin()){
                d.insert(*ms.begin()-x);
            }
            else if(ms.size()>1){
                auto pt=prev(it);
                d.erase(d.find(*it-*pt));
                d.insert(x-*pt);
                d.insert(*it-x);
            }
            ms.insert(x);
            cout<<(*prev(d.end())+*prev(ms.end()))<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
