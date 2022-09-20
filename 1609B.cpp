#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; int q;
    cin>>n>>q;
    string s; cin>>s;
    int count=0;
    for(int i=0;i<n-2;i++){
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            count++;
        }
    }
    for(int j=1;j<=q;j++){
        char x; int pos;
        int X=0,Y=0;
        cin>>pos>>x;
        pos--;
        for(int i=pos-1;i<=pos+1 && i<n;i++){
            if(s[i-1]=='a' && s[i]=='b' && s[i+1]=='c'){
                X++;
            }
        }
        s[pos]=x;
        for(int i=pos-1;i<=pos+1 && i<n;i++){
            if(s[i-1]=='a' && s[i]=='b' && s[i+1]=='c'){
                Y++;
            }
        }
        cout<<count+Y-X<<endl;
        count=count+Y-X;
    }

}