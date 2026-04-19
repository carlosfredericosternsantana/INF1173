#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n ; 
    cin >> n ;
    vector<ll> v (n);
    ll totalXor = 0;
    forn(i,0,n) {
      cin >> v[i];
      totalXor = totalXor^v[i];
    }
    // vai cancela um monte de xor ai kkkkkkkkk
    forn(i,0,n) {
      cout << (v[i]^totalXor) ;
      if (i!=n-1) 
         cout << " ";
    }
    cout << ln;
    return 0 ; 
  }