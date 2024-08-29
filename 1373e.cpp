#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_test(){
        int n, k;
        cin>>n>>k;
        set<int> sn;
        for(int l=0; l<=9; ++l){
                int b=0;
                for(int j=0; j<=k; ++j) b+=(l+j)%10;
                for(int pref=0; pref<=17; ++pref){
                        // prefix of 9s in x
                        int len=min(l+k,9ll)-l+1;
                        int nine=(pref*9ll)*len;
                        for(int d=0; d<9; ++d){
                                int c=d*len+(k+1-len)*(d+1);
                                c+=nine+b;
                                if(c>n) continue;
                                int m=n-c;
                                if(m%(k+1)) continue;
                                m/=k+1;
                                // make smallest number with sum = m
                                string t=to_string(m%9)+string(m/9,'9');
                                t+=to_string(d)+string(pref,'9')+to_string(l);
                                sn.insert(stoll(t));
                        }
                }
        }
        cout<<(sn.empty() ? -1 : *sn.begin())<<'\n';
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
