#include <bits/stdc++.h>
using namespace std;

void prime_factors_decomposition(int x, map<int,int> & mp){
    vector<pair<int,int>>f;
    for(int i=2;i<=x/i;i++){
        while(x%i==0){
            x/=i; mp[i]++;
        }
    }
    if(x>1) mp[x]++;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int ttc=1;
    cin>>ttc;
    while(ttc--){
        int n; cin>>n;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            prime_factors_decomposition(x,mp);
        }
        long long res=0, cnt=0;
        for(auto p:mp){
            res+=(p.second)/2;
            p.second%=2;
            if(p.second) ++cnt;
        }
        res+=cnt/3;
        cout<<res<<"\n";
    }
}