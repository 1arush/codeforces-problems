#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int arr[n][2];
    map<int,int>m; 
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        arr[i][1]=i;
        m[arr[i][0]]+=1;
    }
    for(auto pair : m){
        if(pair.second==1){
            cout<<-1<<"\n";
            return;
        }
    } int i=0;
    while(i<n-1){
        if(arr[i][0]==arr[i+1][0]){
            swap(arr[i][1],arr[i+1][1]); i+=2;
        }
        else{
            swap(arr[i][1],arr[i-1][1]); i++;
        }
    }
    if(m[arr[n-1][0]]%2==1){
        swap(arr[n-1][1],arr[n-2][1]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i][1]+1<<" ";
    }
    return;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        solve(n);
        cout<<"\n";
    }
}