#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll fSqrt(ll x){
    ll start=0,end=2000000150;
    while (end>start){
        ll mid =start+(end-start)/2; 
        if(mid*mid>x) end=mid;
        else start=mid+1;
    }
    return start-1;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll l,r; cin>>l>>r;
        ll leftV=fSqrt(l),rightV=fSqrt(r);
        ll count;
        if(leftV==rightV) count=0;
        else count=3*(rightV-leftV-1);
        vector<ll>left(3),right(3);
        left[0]=leftV*leftV; right[0]=rightV*rightV; 
        for(int i=1;i<3;i++){
            right[i]=right[i-1]+rightV;
            left[i]=left[i-1]+leftV;
        }
        if(leftV==rightV){
            for(int i=0;i<3;i++){
                if(left[i]>=l and left[i]<=r) count++;
            }
            cout<<count<<'\n'; continue;
        }
        for(int i=0;i<3;i++){
            if(left[i]>=l and left[i]<=r) count++;
            if(right[i]<=r and right[i]>=l) count++;
        }
        cout<<count<<'\n';
    }
}