#include <iostream>
#include <stdio.h>
int main(){
    long long n; std::cin>>n;
    long long hex=1+3*n*(n+1);
    std::cout<<hex;
}