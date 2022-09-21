#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cout<<j+1<<' '<<j+2<<"\n";
            }
        }
    }
}