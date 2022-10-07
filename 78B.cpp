#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    int r=n%7; n-=r;
    string s="ROYGBIV";
    vector<string>color={"G","YG","OYG","ROYG","ROBYG","ROIBYG"};
    for(int i=0;i<n/7;i++) cout<<s;
    cout<<color[r-1];
}