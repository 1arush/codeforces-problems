#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  for(int &i:a) cin>>i;
  vector<pair<int,int>> segs;
  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r, --l, --r;
    segs.emplace_back(l,r);
  }
  // sort(segs.begin(),segs.end());
  vector<bool> taken(m,0);
  int cost=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      // i is max, and j is min
      int M=a[i], mi=a[j];
      vector<bool> now(m);
      for(int k=0; k<m; k++){
        auto [l,r]=segs[k];
        if(j>=l && j<=r && (i<l || i>r)){
          now[k]=true; mi--;
        }
      }
      if(M-mi>cost){
        cost=M-mi, taken=now;
      }
    }
  }
  int s=accumulate(taken.begin(),taken.end(),0);
  cout<<cost<<'\n'<<s<<'\n';
  for(int i=0; i<m; i++){
    if(taken[i]) cout<<i+1<<' ';
  }
  return 0;
}
