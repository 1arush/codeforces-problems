#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;
#define double long double

const double eps=1e-8;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t_;
  cin>>t_;
  while(t_--){
    int n;
    cin>>n;
    vector<pair<double,double>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].first; // x[i]
    for(int i=0; i<n; i++) cin>>v[i].second; // t[i]
    sort(v.begin(),v.end());
    double l=0, r=1e12;
    auto possible=[&](double m){
      // check if intersection of intervals is non-empty
      double mn=0, mx=1e11;
      for(int i=0; i<n; i++){
        if(v[i].second>m) return false;
        double d=m-v[i].second;
        mn=max(mn,v[i].first-d);
        mx=min(mx,v[i].first+d);
      }
      return mx-mn>=eps;
    };
    while(r>l+eps){
      double m=(l+r)/2;
      if(possible(m)) r=m;
      else l=m;
    }
    double mn=0, mx=1e11;
    for(int i=0; i<n; i++){
      if(v[i].second>r) return false;
      double d=r-v[i].second;
      mn=max(mn,v[i].first-d);
      mx=min(mx,v[i].first+d);
    }
    cout<<fixed<<setprecision(15)<<mx<<'\n';
  }
  return 0;
}
