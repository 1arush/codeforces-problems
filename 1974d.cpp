#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve_test(){
        int n;
        string s;
        cin>>n>>s;
        string ans;
        int rx=0, ry=0, hx=0, hy=0;
        for(auto &c:s){
                if(c=='N'){
                        if(ry>hy){
                                ++hy, ans+='H';
                        }else{
                                ++ry, ans+='R';
                        }
                }else if(c=='S'){
                        if(ry<hy){
                                --hy, ans+='H';
                        }else{
                                --ry, ans+='R';
                        }
                }
                else if(c=='E'){
                        if(rx>hx){
                                ++hx, ans+='H';
                        }else{
                                ++rx, ans+='R';
                        }
                }else{
                        if(rx>hx){
                                --rx, ans+='R';
                        }else{
                                --hx, ans+='H';
                        }
                }
        // cout<<rx<<' '<<hx<<'\n';
        // cout<<ry<<' '<<hy<<'\n';
        }
        if(rx!=hx || ry!=hy){
                cout<<"NO\n"; return;
        }
        int cnt=count(ans.begin(),ans.end(),'H');
        if(cnt!=n && cnt!=0){
                cout<<ans<<'\n'; return;
        }
        map<char,int> mp;
        for(int i=0; i<n; ++i){
                char c=s[i];
                if((c=='N' && mp['S'])||(c=='S' && mp['N'])){
                        if(cnt==0){
                                int p=(c=='N' ? mp['S'] : mp['N']);
                                ans[i]='H', ans[p]='H';
                        }else{
                                int p=(c=='N' ? mp['S'] : mp['N']);
                                ans[i]='R', ans[p]='R';
                        }
                        break;
                }else if((c=='W' && mp['E'])||(c=='E' && mp['W'])){
                        if(cnt==0){
                                int p=(c=='W' ? mp['E'] : mp['W']);
                                ans[i]='H', ans[p]='H';
                        }else{
                                int p=(c=='W' ? mp['E'] : mp['W']);
                                ans[i]='R', ans[p]='R';
                        }
                        break;
                }
                mp[c]=i;
        }
        cnt=count(ans.begin(),ans.end(),'H');
        // cout<<cnt<<'\n';
        if(cnt==0 || cnt==n){
                cout<<"NO\n";
                return;
        }
        cout<<ans<<'\n';
}

int32_t main(){
        ios::sync_with_stdio(0), cin.tie(0);

        int _test=1;
        cin>>_test;
        while(_test--){
                // cout<<'\n';
                solve_test();
        }
        return 0;
}
