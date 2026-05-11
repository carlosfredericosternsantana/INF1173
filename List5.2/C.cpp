#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
#define vll vector<ll>
bool bfs (vector<vll>& grid , vector<vector<char>>& vchar, map<char,vll>& Map , ll n , ll m ) {
  vll dx = {1,-1,0,0};
  vll dy = {0,0,1,-1};
  queue<pair<ll,ll>> q ;
  
  q.push(make_pair(0,0));
  grid[0][0] = 1; 
  
  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    forn(i,0,4) 
      if (p.first+dx[i]>=0 && p.first+dx[i]<=n-1 && p.second+dy[i]>=0 && p.second+dy[i]<=m-1)
        if (grid[p.first+dx[i]][p.second+dy[i]]==0) {
          q.push(make_pair(p.first+dx[i],p.second+dy[i]));
          grid[p.first+dx[i]][p.second+dy[i]] = grid[p.first][p.second]+1;
        }
    if (vchar[p.first][p.second]!='.' && vchar[p.first][p.second]!='#') {
      for (ll k : Map[vchar[p.first][p.second]]) {
        if (grid[k/m][k%m]==0) {
          q.push(make_pair(k/m,k%m));
          grid[k/m][k%m] = grid[p.first][p.second]+1;
        }
      }
      Map[vchar[p.first][p.second]].clear(); 
    }
  }

  return grid[n-1][m-1]>0;
}
int main (void) {
  
  ll n , m ;
  cin >> n >> m ;
  vector<vll> v(n,vll(m)); 
  map<char,vll> Map;
  vector<vector<char>> vchar(n,vector<char>(m));
  
  forn(i,0,n)
    forn(j,0,m) {
      char c ;
      cin >> c ;
      vchar[i][j]=c;
      if (c=='#')
        v[i][j]=-1;
      else {
        v[i][j] = 0;
        if (c!='.')
          Map[c].push_back(i*m+j);
      }
    }
  
  cout << (bfs(v,vchar,Map,n,m)? v[n-1][m-1]-1 : -1);
  
  
  return 0 ;
}