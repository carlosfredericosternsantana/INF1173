#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
#define vll vector<ll>
struct DSU {
  vll parents ; 
  vll sizes ; 
  vll howManyBlackNodes;
  
  vector<bool> isBlack;
  public: DSU (ll size) {
    sizes.assign(size,1);
    howManyBlackNodes.assign(size,0);
    isBlack.assign(size,false);
    forn(i,0,size)
      parents.push_back(i);
  }
  ll find (ll node) {
    if (parents[node]!=node) 
      parents[node]=find(parents[node]);
    return parents[node];
  }
  void Union (ll n1 , ll n2) {
    ll p1 = find(n1);
    ll p2 = find(n2);
    if (p1!=p2) {
      if (sizes[p1]>sizes[p2]) {
        sizes[p1]+=sizes[p2];
        howManyBlackNodes[p1]+=howManyBlackNodes[p2];
        parents[p2]=find(p1);
        
      }
      else {
        sizes[p2]+=sizes[p1];
        parents[p1]=find(p2);
        howManyBlackNodes[p2]+=howManyBlackNodes[p1];
      }
      
    }
  }
  void ToggleColor (ll node) {
    isBlack[node]=!isBlack[node];
    if (isBlack[node])
      howManyBlackNodes[find(node)]++;
    else
      howManyBlackNodes[find(node)]--;
  }
  
  bool query (ll node) {
    return howManyBlackNodes[find(node)]>0;
  }
};

int main() {    
  ll n , q ;
  cin >> n >> q;
  vector<bool> ans;
  DSU dsu = DSU(n);
  forn(i,0,q) {
    ll qtype , fp ;// query type and first parameter
    cin >> qtype >> fp;
    switch (qtype) {
      case 2 :
        dsu.ToggleColor(--fp);
      break;
      case 3 :
        ans.push_back(dsu.query(--fp));
      break;
      case 1:
        ll sp ;
        cin >> sp;
        dsu.Union(--fp,--sp);  
      break;
    }
  }
  for (bool b : ans)
    cout << (b?"Yes":"No") << ln;
  return 0;
}