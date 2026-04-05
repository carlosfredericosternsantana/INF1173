#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll productBytime (vector<ll>& v , ll t) {
  ll result = 0 ;
  forn(i,0,v.size()) 
    result += (t/v[i]);
  return result;
}
ll binarySearch (vector<ll>& v , ll min_t , ll product) {
  ll r = product*min_t ; 
  ll l = 1;
  ll ans = r ; 
  while (l<=r) {
    ll mid = (r+l)/2; // stands for time 
    if (productBytime(v,mid)<product) 
      l = mid+1;
    else {
      ans = mid ; 
      r = mid-1;
    }
    
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
  
    ll n , x ;
    ll maxt  = 0 ;
    ll mint = 1e9;
    cin >> n >> x ; 
    vector<ll> v(n);
    
    forn(i,0,n) {
      cin >> v[i];
      mint = min(mint,v[i]);
    }
   ll out = binarySearch(v,mint,x); 
   cout << out << ln;

    return 0;
}