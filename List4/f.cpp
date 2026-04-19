#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);;
    ll n ; 
    cin >> n ;
    
    ll sum = 0;
    ll arraySum = 0 ;
    vector<ll> v(n);
    vector<ll> prefiXor(n+1,0);
    forn(i,0,n) {
      cin >> v[i];
      arraySum+=v[i];
    }
    forn(i,1,n+1) 
      prefiXor[i] = prefiXor[i-1]^ v[i-1];
      
    forn(j,0,64) {
      ll counter = 0 ;
      forn(i,0,n+1) 
        if(prefiXor[i]&(1ll<<j))
          counter++;
      ll couples  = counter*(n+1-counter);
      ll partialSum = couples*(1ll<<j);
      sum+=partialSum;
    }
    
    cout << sum-arraySum << ln;
    return 0 ; 
  }