#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        } int max=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p=i,q=j;
                int S1=0;
                while(p<n && q>=0 && p>=0 && q<m){
                    S1+=a[p][q]; p--; q--;
                } p=i; q=j;
                while(p<n && q>=0 && p>=0 && q<m){
                    S1+=a[p][q]; p++; q++;
                } p=i; q=j;
                while(p<n && q>=0 && p>=0 && q<m){
                    S1+=a[p][q]; p--; q++;
                } p=i; q=j;
                while(p<n && q>=0 && p>=0 && q<m){
                    S1+=a[p][q]; p++; q--;
                } S1-=a[i][j]*3;
                if(S1>max) max=S1;
            }
        }
        cout<<max<<"\n";
    }
}