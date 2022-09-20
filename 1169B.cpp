#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool Q(int x, int y, vector<pair<int,int>>v){
    for(auto p:v){
        if(!(p.first==x or p.first==y or p.second==x or p.second==y)) return 0;
    }
    return 1;
}
int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    bool found=0;
    vector<int>w={v[0].first,v[0].second};
    for(int i=0;i<=1;i++){
        for(auto p:v){
            if(p.first!=w[i] and p.second!=w[i]){
                found=1;
                int a=p.first,b=p.second;
                if(Q(w[i],a,v)){
                    cout<<"YES\n"; return 0;
                }
                if(Q(w[i],b,v)){
                    cout<<"YES\n"; return 0;
                }
                break;
            }
        }
        if(!found){
            cout<<"YES\n"; return 0;
        }
    }
    cout<<"NO\n"; return 0;

}