#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int ct=0;
        for(int p=0;p<n;p++){
            for(int q=p+1;q<n;q++){
                if(a[p]>=a[q]) ct++;
            }
        }
        cout<<ct<<"\n";
    }
}