#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int kmp(string &s){
        // p[i] is the length of longest prefix  (1-base)
        // in [0,i) which is also a suffix of this substring
        const int n=s.size();
        vector<int> p(n+1);
        p[0]=-1;
        for(int i=1; i<=n; ++i){
                int k=p[i-1];
                while(k>=0 && s[k]!=s[i-1]){
                        k=p[k];
                }
                p[i]=k+1;
        }
        return p[n];
}

void solve_test(){
        int n;
        cin>>n;
        vector<string> s(n);
        string ans;
        for(int i=0; i<n; ++i){
                cin>>s[i];
                // optimize by considering only shortest of ans and s[i]
                if(i){
                        int p=ans.size(), q=s[i].size();
                        string t=s[i]+'#';
                        if(p<q){
                                t+=ans;
                        }else{
                                t+=ans.substr(p-q,q);
                        }
                        int v=kmp(t);
                        ans+=s[i].substr(v);
                }else{
                        ans+=s[i];
                }
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int t=1;
        // cin>>t;
        while(t--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
