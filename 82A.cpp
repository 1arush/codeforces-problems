#include <bits/stdc++.h>
typedef long long int ll;
#define endl "\n";
using namespace std;
int sum(int n){
    return pow(2,n)-1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<string>v={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int n; cin>>n;
    int i=0;
    while(5*sum(i)<=n) i++;
    n-=5*sum(i-1);
    i=pow(2,i-1);
    // cout<<n<<" "<<i<<endl;
    if(n==0) cout<<v[4];
    else if(n%i==0) cout<<v[(n-1)/i];
    else cout<<v[n/i];


}