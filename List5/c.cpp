#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

void bfs (ll source , ll end , vector<vector<ll>>& adjList , vector<bool>& visited , vector<ll>& parents) {
  queue<ll> q ;
  q.push(source);
  visited[source] = true; 
  while(!q.empty()) {
    ll next = q.front();
    q.pop();
    
    for (ll u : adjList[next])
      if(!visited[u]) {
        visited[u] = true; 
        parents[u] = next;
        q.push(u);
        if(u == end) 
          return; 
      }
  }
}

ll pathBuilder (ll end , vector<ll>& path ,vector<ll>& parents ) {
  path.push_back(end);
  if(parents[end] == -1) 
    return 1 ;
  return 1 + pathBuilder(parents[end], path, parents);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n , m ; 
    if(!(cin >> n >> m)) return 0;
    
    vector<vector<ll>> adjList (n);
    forn(i,0,m) {
      ll a , b ;
      cin >> a >> b ; 
      adjList[--b].push_back(--a);
      adjList[a].push_back(b);
    }
    
    vector<bool> visited(n,false);
    vector<ll> parents(n,-1);
    vector<ll> path;
    
    bfs(0, n-1, adjList, visited, parents);
    
    if(!visited[n-1]) {
        cout << "IMPOSSIBLE" << ln;
    } 
    else {
        ll distance = pathBuilder(n-1, path, parents);
        cout << distance << ln;
        for (ll i = path.size()-1; i >= 0; i--) {
            cout << path[i] + 1;
            if(i > 0) cout << " ";
        }
        cout << ln;
    }
    
    return 0;
}