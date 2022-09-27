#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,start,end; cin>>n>>start>>end;
    string airports; cin>>airports;
    start--; end--;
    if(airports[start]==airports[end]) printf("%d",0);
    else printf("%d",1);
}