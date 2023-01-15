#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define io freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#define print(res) { cout<<res<<'\n'; return 0; }

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define add(s,x) { int x; cin>>x; s+=char(48+x); }
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,res=0; cin>>n;
    int k1; cin>>k1;
    string s1="",s2="";
    forn(i,k1) add(s1,x)
    int k2; cin>>k2; 
    forn(i,k2) add(s2,x)
    bool win=0;
    string c1=s1,c2=s2;
    while(res<3.7*1e6){
        res++;
        if(s1[0]<s2[0]){
            win=1;
            s2+=s1[0]; s2+=s2[0];
            s1.erase(0,1);
            s2.erase(0,1);
        }
        else{
            win=0;
            s1+=s2[0]; s1+=s1[0];
            s1.erase(0,1);
            s2.erase(0,1);
        }
        if(s1==c1 and s2==c2) print(-1)
        if(s1.size()==0 or s2.size()==0){
            cout<<res<<" "<<int(win)+1; return 0;
        }
    }
    print(-1)
}