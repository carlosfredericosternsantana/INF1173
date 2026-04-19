#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll mod = 1e9+7;
    ll n ; 
    cin >> n ;
    
    vector<ll> v(n);
    ll sum = 0 ;
    forn(i,0,n)
      cin >> v[i];
    
    forn(i,0,60) {
      ll counter = 0;
      forn(j,0,n) {
       if(v[j]&(1ll<<i)) 
        counter++;
      }
      ll couples = counter*(n-counter);
      ll partialSum = (couples%mod) * ((1ll<<i)%mod);
      sum = (sum+partialSum)%mod;
    }
    cout << sum << ln;
    return 0 ; 
  }