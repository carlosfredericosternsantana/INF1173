#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll howManySubArrays (vector<ll>& v , ll k) {
  // how many subarrays we make for a maximum k ...
  ll result = 1 ;
  ll sum = 0 ;
  forn(i,0,v.size()) {
    if (sum+v[i]<=k) {
      sum+=v[i];
    }
    else {
      result++;
      sum = v[i];
    }
  }
  return result;
}
ll binarySearch (vector<ll>& v , ll subarrayNums , ll total_sum , ll maxAllElements) {
  ll l = maxAllElements ; // the minimum sum possibility would be the one-sized array containing the highest integer
  ll r = total_sum; // the maximum sum possibility would be n-sized array containing all input integers
  ll ans = total_sum ; 
  while(l<=r) {
    ll mid = (l+r)/2;
    ll valueForMid = howManySubArrays(v,mid);
    if (valueForMid<=subarrayNums) {
      ans = mid;
      r=mid-1;
    }
    else {l=mid+1;}
    
  }
  return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n , k ; 
    ll total_sum = 0;
    ll maximo = 0;
    cin >> n >> k ;
    vector<ll> v(n);
    
    forn(i,0,n) {
      cin >> v[i];
      total_sum+=v[i];
      maximo = max(maximo,v[i]);
    }
    cout << binarySearch(v,k,total_sum,maximo) << ln;
    
    return 0;
}