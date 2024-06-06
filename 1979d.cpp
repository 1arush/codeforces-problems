#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool chk(string &s, int k, int z){
        const int n=s.size();
        vector<bool> v(n);
        for(int i=0; i<n; ++i){
                int p=((i/k)%2==0 ? z : 1-z);
                v[i]=(s[i]-'0')==p;
        }
        int cn=count(v.begin(),v.end(),1);
        return cn==n;
}

void solve_test(){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(chk(s,k,0) || chk(s,k,1)){
                cout<<n<<'\n'; return;
        }
        int d=n-2;
        while(d>=0 && s[d]==s[d+1]) --d;
        d=(n-d-1)%k;
        int i=0;
        while(i<n){
                int j=i+1;
                while(j<n && s[j]==s[i]) ++j;
                if(j-i!=k){
                        if(j-i<k-d || (d!=0 && s[i]!=s[n-1])){
                                cout<<-1<<'\n'; return;
                        }
                        string f=s.substr(0,i+k-d);
                        string b=s.substr(i+k-d,n-(i+k-d));
                        reverse(f.begin(),f.end());
                        b+=f;
                        if(chk(b,k,0) || chk(b,k,1)){
                                cout<<i+k-d<<'\n';
                        }else{
                                cout<<"-1\n"; 
                        }
                        return;
                }
                i=j;
        }
        cout<<"-1\n";
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
