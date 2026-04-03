#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {   
  ios::sync_with_stdio(0); cin.tie(0);
  
  ll n ;
  vector<ll> v ; 
  ll g ; // greatest value until ...
  ll op = 0 ; // operation's number
  cin >> n ; 
  forn(i,0,n) {
    ll inpt ; 
    cin >> inpt ; 
    v.push_back(inpt);
  }
  g = v[0];
  forn(i,0,n) {
    g = max(g,v[i]);
    if (v[i]<g) 
      op += (g-v[i]);
  }
  cout << op << ln;
    return 0;
}