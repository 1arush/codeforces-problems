#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        set<int> s;
        for(int i=1; i<=n; i++) s.insert(i);
        bool bad=false;
        for(int i=2; i<=n; i+=2){
            cin>>a[i];
            if(s.count(a[i])==0) bad=true;
            else s.erase(a[i]);
        }
        if(bad){
            cout<<-1<<'\n'; continue;
        }
        for(int i=n-1; i>0; i-=2){
            auto f=s.lower_bound(a[i+1]);
            if(f==s.begin()){
                bad=true; break;
            }
            --f;
            a[i]=*f; s.erase(f);
        }
        if(bad){
            cout<<-1<<'\n'; continue;
        }
        for(int i=1; i<=n; i++) cout<<a[i]<<' ';
        cout<<'\n';
    }   
    return 0;
}