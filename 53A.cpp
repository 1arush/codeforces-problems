#include <bits/stdc++.h>
using namespace std;
bool start(string haystack, string needle, int a, int b){
    if(a<b) return 0;
    for(int i=0;i<b;i++){
        if(haystack[i]!=needle[i]) return 0;
    }
    return 1;
}
int main(){
    string s; int n;
    cin>>s>>n;
    map<string,int>m;
    for(int i=0;i<n;i++){
        string temp; cin>>temp; m[temp]++;
    } bool P=0;
    string answer="";
    for(int i=0;i<100;i++) answer+="z";
    for(auto pair:m){
        if(start(pair.first,s,pair.first.length(),s.length()) and pair.first<answer){
            P=1; answer=pair.first;
        }
    }
    if(P) cout<<answer;
    else cout<<s;
}