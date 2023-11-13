#include <bits/stdc++.h>
#define debug(x) (cout<<'['<<(#x)<<':'<<(x)<<']'<<'\n')
using namespace std;

const int S=325; // block-size ~sqrt(N)

struct DataStructure{
  // data structure for current segment
  int N, ans;
  vector<int> cnt;
  DataStructure(int n){
    N=n, ans=0;
    cnt.resize(n);
  }
  void add(int x){
    if(x>=N) return;
    cnt[x]++;
    if(cnt[x]==x) ans++;
    if(cnt[x]==x+1) ans--;
  }
  void remove(int x){
    if(x>=N) return;
    cnt[x]--;
    if(cnt[x]==x) ans++;
    if(cnt[x]==x-1) ans--;
  }
};

struct Query{
  int l,r,bn,id;
  // l,r : borders, bn : block-number, id : query-id
  Query(int L,int R, int idx){
    l=L, r=R, id=idx, bn=L/S;
  }
  bool operator <(Query other) const{
    // comparator (for sorting)
    if(bn!=other.bn) return bn<other.bn;
    return r<other.r;
  }
};

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(int &u:a) cin>>u;
  vector<Query> v;
  for(int i=0; i<q; i++){
    int l,r;
    cin>>l>>r, --l, --r;
    v.push_back(Query(l,r,i));
  }
  sort(v.begin(),v.end());
  vector<int> res(q);
  DataStructure ds(n+1);
  int cl=0, cr=0;
  ds.add(a[cl]);
  for(auto &Q:v){
    int l=Q.l, r=Q.r, id=Q.id;
    while(cl>l) ds.add(a[--cl]);
    while(cr<r) ds.add(a[++cr]);
    while(cl<l) ds.remove(a[cl++]);
    while(cr>r) ds.remove(a[cr--]);
    res[id]=ds.ans;
  }
  for(int x:res) cout<<x<<'\n';
  return 0;
}
