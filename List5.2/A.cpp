#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
#define vll vector<ll> 
#define INF 1e18

struct compare {
  bool operator()(const pair<ll,ll>& p1, const pair<ll,ll>& p2) const {
    return p1.second > p2.second;
  }
};

void dj (vll& dist , vector<vector<pair<ll,ll>>>& edges , ll n) {
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , compare> pq;
  dist[0]=0;
  pq.push({0,0});
  while (!pq.empty()) {
    auto next = pq.top();
    pq.pop();
    if (next.second > dist[next.first])
      continue;

    for (auto &e : edges[next.first]) {
      ll i = e.first;
      ll w = e.second;
      if (dist[next.first] + w < dist[i]) {
        dist[i] = dist[next.first] + w;
        pq.push({i, dist[i]});
      }
    }
  }
}

int main (void) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n , m ;
    cin >> n >> m ;
    
    vll dist (n,INF);
    vector<vector<pair<ll,ll>>> edges (n);
    
    forn(i,0,m) {
        ll a , b , c ; 
        cin >> a >> b >> c;
        --a;
        --b;
        edges[a].push_back({b,c});
    }

    dj(dist,edges,n);

    forn (i,0,n) {
      cout << dist[i] << (i==n-1? ln : " ");
    }
    return  0 ; 
}