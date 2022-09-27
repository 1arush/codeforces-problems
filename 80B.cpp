#include <bits/stdc++.h>
typedef long double ld;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s; cin>>s;
    float hour=(s[0]-48)*10+(s[1]-48); float minute=(s[3]-48)*10+(s[4]-48);
    ld x=0,y=0;
    if(hour>=12){
        x=(((hour-12)*60+minute)/60)*30;
        y=(minute)*6;
    }
    else{
        x=((hour*60+minute)/60)*30;
        y=(minute)*6;
    }
    cout<<x<<' '<<y;
}