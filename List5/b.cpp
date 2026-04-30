#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll dfs (ll node , vector<vector<ll>>& v , vector<ll>& sub ) {
  ll result = 0 ;
  for (ll u : v[node])
    result+=(1+dfs(u,v,sub));
  sub[node]=result;
  return result;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n ; 
    cin >> n ; 
    vector<vector<ll>> adjList (n);
    vector<ll> sub (n);
    forn(i,1,n) {
      ll b ; 
      cin >> b ; 
      adjList[--b].push_back(i);
    }
    dfs(0,adjList,sub);
    forn(i,0,n)
      cout << sub[i] << ln;
    
    return 0;
}