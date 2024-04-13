#include <bits/stdc++.h>
using namespace std;
#define int int64_t

string s, t;
int n;

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif

        int _;
        cin>>_;
        while(_--){
                cin>>s>>t;
                n=s.size();
                bool f=0;
                for(int i=0; i<n; ++i){
                        if(f){
                                if(s[i]>t[i]) swap(s[i],t[i]);    
                        }else if(s[i]!=t[i]){
                                f=1;
                                if(s[i]<t[i]) swap(s[i],t[i]);
                        }
                }
                cout<<s<<'\n'<<t<<'\n';
        }
        return 0;
}
