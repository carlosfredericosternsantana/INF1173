#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

 ll leastSignificativeBit (ll num) {
   ll k = 1;
   forn(i,0,64) {
     if (num & (k<<i)) 
      return i;
   }
   return -1;
 }

void solve () {
  ll n ; 
  cin >> n ; 
  
  if (n==1 || n==2) {
    cout << -1 << ln;
    return;
  }
  ll a = (1ll << leastSignificativeBit(n));
  cout << a << " " << (n^a) << ln;
  
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t ; 
    cin >> t;
    while (t--) {
      solve();
    }
    
  
    return 0 ; 
  }