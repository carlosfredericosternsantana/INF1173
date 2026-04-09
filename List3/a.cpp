#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n , k;
    cin >> n >>  k ;
    vector<ll> v (n);
    
    forn(i,0,n) cin >> v[i];
    
    ll i = 0 ;
    ll j = 0 ;
    ll sum = 0 ;
    ll ans = 0 ;
    
    while (i<=n && j<=n) {
      if (sum<k) 
        sum+=v[j++];
      else {
        if(sum==k) 
          ans++;
        sum-=v[i++];
      }
      
    }
    cout << ans << ln;
    return 0;
}
