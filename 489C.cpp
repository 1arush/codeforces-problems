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
    int m,s; cin>>m>>s;
    if(s==0 and m==1) print("0 0")
    if(s<1 || s>9*m) print("-1 -1")
    string l="1",r="1";
    forn(i,m-1){
        l+="0"; r+="0";
    }
    int k=s-1,i=0;
    while(k>0){
        char t=r[i];
        r[i]=48+min(9,r[i]+k-48);
        k-=(r[i++]-t);
    }
    i=m-1; k=s-1;
    while(k>0){
        char t=l[i];
        l[i]=48+min(9,l[i]+k-48);
        k-=(l[i--]-t);
    }
    print(l<<" "<<r)
}