#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll mostSignificativeBit (ll num) {
  ll result = -1;
  forn(i,0,64) {
    if ((1ll<<i)&num) 
      result = i;
  }
  return result;
}
ll howMany0s (ll num , ll msb ) {
  // msb stands for mostSignificativeBit
  ll zeros = 0;
  forn(i,0,msb+1) {
    if (!((1ll<<i)&num)) {
      zeros++;
    }
  }
  return zeros;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n ; 
    cin >> n ; 
    
    cout << (1ll<<howMany0s(n,mostSignificativeBit(n))) << ln;
    
  
    return 0 ; 
  }