#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n , x ; 
    ll out = 0 ;
    cin >> n >> x ; 
    vector<ll> v (n);
    
    forn(i,0,n) {
      cin >> v[i];
    }
    sort(v.begin(),v.end());
    
    ll i = 0 ;
    ll j = n-1 ;
    while(i<=j) {
      if (v[i]+v[j]<=x) {
        j--;
        i++;
      }
      else 
        j--;
      out++;
    }
    
    cout << out << ln;
    return 0;
}