#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int rem=n%3,quo=n/3;
    if(rem==2) quo++;
    cout<<quo/12<<" "<<quo%12;
}