#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(res) { cout<<res<<'\n'; return 0; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int>v(n+1);
    int dp[n+1][3];
    // 0 - rest,  1 - contest, 2 - sport
    forn(i,n){
        cin>>v[i];
        forn(j,3) dp[i][j]=0;
    }
    forn(i,n){
        dp[i+1][0]=max(dp[i][0], max(dp[i][1], dp[i][2]));
        if(v[i]==1 || v[i]==3)
            dp[i+1][1]=max(dp[i][2],dp[i][0])+1;
        else
            dp[i+1][1]=0;
        if(v[i]==3 || v[i]==2)
            dp[i+1][2]=max(dp[i][1],dp[i][0])+1;
        else
            dp[i+1][2]=0;
    }
    cout<<n-max(dp[n][0], max(dp[n][1], dp[n][2]));
}