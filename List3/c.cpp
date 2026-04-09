#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll getSubSequenceSum (ll start , ll end , vector<ll>& prefixSum) {
  if (start==-1) 
    return prefixSum[end];
  return prefixSum[end]-prefixSum[start];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll ans = 0 ;
    vector<ll> v (n); // prefix sum
    
    forn(i,0,n) {
      cin >> v[i];
      if (i!=0) 
        v[i]+=v[i-1];
    }
    
    
    ll i  = -1 ;
    ll j = 0 ; 
    while (j<n-1 || i<n-1) {
      ll value = getSubSequenceSum(i,j,v);
      //cout << value << ln;
      if (j<n-1 && value<k) {
        j++;
      }
      else {
        if (value>=k) 
          ans+=(n-j);
        //cout << i << " " << j  << ln;
        i++;
      }
    }
    cout << ans << ln;
    return 0;

      
    }