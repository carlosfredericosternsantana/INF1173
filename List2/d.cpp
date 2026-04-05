#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
  
    ll n , m , k ; 
    ll out = 0;
    cin >> n >> m >> k ;
    vector<ll> customers (n);
    vector<ll> apartments (m);
    
    forn(i,0,n) 
      cin >> customers[i];
    forn(i,0,m) 
      cin >> apartments[i];
      
    sort(customers.begin(),customers.end());
    sort(apartments.begin(),apartments.end());
    
    
  ll i = 0 ;
  ll j = 0 ; 
  while(i<n && j<m) {
    //cout << i << " " << j << ln;
    if (apartments[j]>customers[i]+k) {
      i++;
    }
    else if (apartments[j]<customers[i]-k) {
      j++;
    }
    else {
      i++;
      j++;
      out++;
    }
  }
  
    cout << out << ln;
    return 0;
}