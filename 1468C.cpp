#include <bits/stdc++.h>
using namespace std;
// processing the queries using data structures
int main(){
    map<int,int>M;
    multimap<int,int,greater<int>>Mrev;
    int t; cin>>t;
    int count=0;
    while(t--){
        int query; cin>>query;
        if(query==1){
            count++;
            int mon; cin>>mon;
            M[count]=mon;
            Mrev.insert(make_pair(mon,count));
        }
        else if(query==2){  
            cout<<M.begin()->first<<' '; 
            Mrev.erase(M.begin()->second);     
            M.erase(M.begin());
        }
        else{
            cout<<Mrev.begin()->second<<' ';
            M.erase(Mrev.begin()->second);
            Mrev.erase(Mrev.begin());
        }
    }
}