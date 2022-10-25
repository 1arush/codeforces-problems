#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<=n;i++)
int main(){
    int n,k; cin>>n>>k;
    int cnt=0;
    forn(i,n-1){
        string s; cin>>s;
        int a[10]={0};
        forn(i,s.length()-1){
            a[s[i]-48]++;
        }
        int r=1;
        forn(i,k){
            if(a[i]==0){
                r=0; break;
            }
        }
        cnt+=r;
    }
    cout<<cnt;
}