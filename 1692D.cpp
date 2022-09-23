#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isP(int h, int m){
    if(m%10==h/10 && m/10==h%10) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int t; cin>>t;
    while(t--){
        vector<pair<int,int>>unQ;
        string s; cin>>s;
        int hour=(s[0]-48)*10+(s[1]-48); int min=(s[3]-48)*10+(s[4]-48);
        int diff,i=0; cin>>diff; int C1=hour,C2=min;
        int count=0;
        if(isP(hour,min)) count++;
            hour+=(min+diff)/60;
            min=(min+diff)%60;
            if(hour>=24) hour=hour%24;
        while(true){
            if(hour==C1 && min==C2) break;
            if(isP(hour,min)){
                // cout<<hour<<' '<<min<<"\n";
                bool P=0;
                for(int w=0;w<unQ.size();w++){
                    if(unQ[w].first==hour && unQ[w].second==min) P=1;
                }
                if(!P){ count++;
                pair<int,int>p={hour,min};
                unQ.push_back(p); }
                else break;
            }
            
            hour+=(min+diff)/60;
            min=(min+diff)%60;
            if(hour>=24) hour=hour%24;
            i++;
        }
        cout<<count<<"\n";
    }
}