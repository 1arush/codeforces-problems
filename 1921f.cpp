// Don't worry, I'm not so cute
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        const int rt=sqrt(n);
        vector<int> a(n+1);
        for(int i=1; i<=n; ++i) cin>>a[i];
        vector<vector<int>> sum(rt,vector<int>(n+1)), one;
        one=sum;
        for(int d=1; d<rt; ++d){
            for(int i=1; i<=d; ++i){
                sum[d][i]=one[d][i]=a[i];
                for(int j=i+d; j<=n; j+=d){
                    sum[d][j]=((j-i)/d+1ll)*a[j]+sum[d][j-d];
                    one[d][j]=a[j]+one[d][j-d];
                }
            }
        }
        while(q--){
            int s,d,k;
            cin>>s>>d>>k;
            int ans=0;
            if(d>=rt){
                for(int c=0; c<k; ++c){
                    ans+=(c+1)*a[s+c*d];
                }
            }
            else{
                ans=sum[d][s+d*(k-1)]-(s-d>=1 ? sum[d][s-d] : 0ll);
                int cnt=one[d][s+d*(k-1)]-(s-d>=1 ? one[d][s-d] : 0ll);
                int f=(s%d==0ll ? d : s%d);
                ans-=max(0ll,(s-f)/d)*cnt;
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
