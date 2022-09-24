#include <iostream>
#include <string>
using namespace std;
int binary(int n){
    string s="";
    while(n>0){
        s=to_string(n%2)+s;
        n/=2;
    } int N=0;
    for(int i=0;i<s.length();i++){
        N*=10; N+=s[i]-48;
    } return N;
}
int main(){
    int num; cin>>num;
    int ct=0,i=1;
    for(i;i<=num;i++){
        if(binary(i)<=num) ct++;
        else break;
    }
    cout<<ct;
}