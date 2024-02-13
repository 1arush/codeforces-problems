#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin>>_;
    while(_--){
        int n,m;
        cin>>n>>m;
        vector<int> a;
        int ans=0;
        for(int i=0; i<n; ++i){
            string s;
            cin>>s;
            ans+=(int)s.size();
            int cnt=0, r=(int)s.size()-1;
            while(~r && s[r]=='0') --r, ++cnt;
            a.push_back(cnt);
        }
        sort(a.rbegin(),a.rend());
        for(int i=0; i<n; i+=2){
            ans-=a[i];
        }
        cout<<(ans>m ? "Sasha" : "Anna")<<'\n';
    }
    return 0;
}
