#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

struct Node {
  ll start, end;
  ll queryValue;
  
  Node* R = NULL;
  Node* L = NULL;
  
  Node(int s, int e) {
    this->start = s;
    this->end = e;
  }

  Node* build(int s, int e, vector<ll>& v) {
    Node* n = new Node(s,e);
    if (s == e) {
      n->queryValue = s;
    } else {
      ll mid = (s+e)/2;
      n->R = build(s, mid, v);      
      n->L = build(mid+1, e, v);     

      if (v[n->R->queryValue] <= v[n->L->queryValue])
        n->queryValue = n->R->queryValue;
      else
        n->queryValue = n->L->queryValue;
    }
    return n;
  }

  int query(ll l, ll r, ll val, Node* node, vector<ll>& v) {
    if (node->end < l || node->start > r) return -1;

    if (v[node->queryValue] >= val) return -1;

    if (node->start == node->end) return node->start;

    ll right = query(l, r, val, node->L, v);
    if (right != -1) return right;

    return query(l, r, val, node->R, v);
  }
};

int main() {   
  ios::sync_with_stdio(0); cin.tie(0);
  
  ll n;
  cin >> n;

  vector<ll> v(n), out(n);
  forn(i,0,n) cin >> v[i];

  Node* root = new Node(0, n-1);
  root = root->build(0, n-1, v);

  forn(i,0,n) {
    if (i == 0) out[i] = -1;
    else out[i] = root->query(0, i-1, v[i], root, v);
  }

  forn(i,0,n) cout << out[i] + 1 << '\n';
}