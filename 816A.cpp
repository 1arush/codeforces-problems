#include <bits/stdc++.h>
using namespace std;
bool p(int hr, int min){
    int Q=hr*100+min;
    int rev=min%10; rev*=10; min/=10;
    rev+=min%10; rev*=10;
    rev+=hr%10; rev*=10; hr/=10;
    rev+=hr%10;
    if(rev==Q) return 1;
    return 0;
}
int main(){
    string time; cin>>time;
    int hr=(time[0]-48)*10+(time[1]-48);
    int min=(time[3]-48)*10+(time[4]-48),ans=0;
    while(!p(hr,min)){
        if(min==59){
            if(hr==23) hr=0;
            else hr++;
            min=0;
        }
        else min++;
        ans++;
    }
    cout<<ans;
}