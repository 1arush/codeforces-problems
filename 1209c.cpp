#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n;
        string s;
        cin>>n>>s;
        // if we split into 2 (roughly equal) parts
        // bruteforce value of divider d
        for(int d=0; d<10; ++d){
                vector<int> c(n,-1);
                for(int i=0; i<n; ++i){
                        if(s[i]<char(d+'0')) c[i]=1;
                        if(s[i]>char(d+'0')) c[i]=2;
                }
                int id=0;
                for(; id<n; ++id){
                        if(s[id]>char(d+'0')) break;
                        if(c[id]==-1) c[id]=2;
                }
                for(int i=0; i<n; ++i){
                        if(c[i]==-1) c[i]=1;
                }
                string a, b;
                for(int i=0; i<n; ++i){
                        if(c[i]==1) a+=s[i];
                        else b+=s[i];
                }
                if(is_sorted(a.begin(),a.end()) && is_sorted(b.begin(),b.end())){
                        for(int i=0; i<n; ++i){
                                cout<<c[i];
                        }
                        cout<<'\n';
                        return;
                }
        }       
        cout<<"-\n"; 
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
