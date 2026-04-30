#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
bool dfs (vector<vector<ll>>& adj_list , vector<bool>& visited , vector<bool>& teams , ll node) {
  bool result = true;
  visited[node] = true;
  for (ll next : adj_list[node]) {
    if (!visited[next]) {
      teams[next] = !teams[node];
      result = result && dfs(adj_list,visited,teams,next);
     //cout << teams[next] << " " << teams[node] << ln;
    }
    else if (teams[node]==teams[next]) {
      result = false;
      //cout << node << " " << next << ln;
    }
  }
  return result;
  
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n , m;
  cin >> n >> m ; 
  vector<vector<ll>> adj_list (n);
  vector<bool> visited(n,false);
  vector<bool> teams (n,false);
  forn (i,0,m) {
    ll a , b ;
    cin >> a >> b ;
    adj_list[--a].push_back(--b);
    adj_list[b].push_back(a);
  }
  bool finalResult = true;
  forn(i,0,n) {
    if (!visited[n])
      finalResult = finalResult && dfs(adj_list,visited,teams,i);
  }
  if (finalResult) 
    forn(i,0,n) {
      cout << teams[i]+1;
      if (i!=n-1) cout << " ";
    }
  else 
    cout << "IMPOSSIBLE";
  cout << ln;  
  return 0 ;
}