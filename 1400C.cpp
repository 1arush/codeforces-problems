#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        int n=s.size(), x;
        cin>>x;
        vector<int> w(n,1);
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(i-x>=0) w[i-x]=0;
                if(i+x<n) w[i+x]=0;
            }
        }
        bool flag=true;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(i-x>=0 && w[i-x]!=0) flag=false;
                if(i+x<n && w[i+x]!=0) flag=false;
            }
            else{
                if(i-x>=0 || i+x<n){
                    int cnt=(i-x>=0 && w[i-x]==1)+(i+x<n && w[i+x]==1);
                    if(cnt==0) flag=false;
                }
                else flag=false;
            }
        }
        if(!flag) cout<<-1;
        else{
            for(int i=0; i<n; i++) cout<<w[i];
        }
        cout<<'\n';
    }
    return 0;
}