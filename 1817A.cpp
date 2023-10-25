#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,q;
  cin>>n>>q;
  vector<int> a(n), col(n);
  for(int i=0; i<n; i++) cin>>a[i];
  // x < y -> color 1
  // x <= y -> color 2
  int i=0;
  while(i<n){
    int j=i+1;
    col[i]=0;
    // [i,j) is the segment
    if(a[j]>a[i]){
      while(j<n && a[j]>a[j-1]){
        col[j]=1; j++;
      }
    }
    else{
      while(j<n && a[j]<=a[j-1]){
        col[j]=2; j++;
      }
    }
    if(j==n) break;
    i=j-1;
  }
  col[n-1]=0;
  vector<int> pf(n,1);
  for(int i=1; i<n; i++){
    pf[i]=pf[i-1]+(col[i]==0 || col[i]==1);
  }
  // for(int i=0; i<n; i++) cout<<col[i]<<' '; cout<<'\n';
  // for(int i=0; i<n; i++) cout<<pf[i]<<' '; cout<<'\n';
  while(q--){
    int l,r;
    cin>>l>>r;
    --l, --r;
    if(l==r){
      cout<<1<<'\n';
      continue;
    }
    int cnt=pf[r]-(l==0 ? 0 : pf[l-1]);
    if(col[l]==2) cnt++;
    if(col[r]==2) cnt++;
    cout<<cnt<<'\n';
  }
  return 0;
}
