#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll binarySearch (ll item ,ll firstIndex , ll secondIndex , vector<pair<ll,ll>>& v2) {
  ll L = 0 ;
  ll R = v2.size()-1;
  while(L<=R) {
    ll mid = (L+R)/2;
    if (v2[mid].first == item ) {
        ll altMid  = mid;
        if (v2[mid].second != firstIndex && v2[mid].second != secondIndex) {
         return mid; 
        }
        while (altMid >= 0 && v2[altMid].first == item) {
            if (v2[altMid].second != firstIndex && v2[altMid].second != secondIndex)
                return altMid;
            altMid--;
        }

        altMid = mid + 1;
        while (altMid < (ll)v2.size() && v2[altMid].first == item) {
            if (v2[altMid].second != firstIndex && v2[altMid].second != secondIndex)
                return altMid;
            altMid++;
        }

        return -1;
    }
    else if (v2[mid].first < item) {
      L = mid+1;
    }
    else {
      R = mid-1;
    }
  }
  return -1;
}

bool compare (pair<ll,ll>& p1 , pair<ll,ll>&p2) {
  return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n , k ; 
    cin >> n >> k ; 

    vector<ll> v(n);
    vector<pair<ll,ll>> v2;

    forn(i,0,n) {
      cin >> v[i];
      v2.push_back(make_pair(v[i],i));
    }

    sort(v2.begin(),v2.end(),compare);

    forn(i,0,n) {
        ll ans = -1;
        forn(j,i+1,n) {

          ll target = k - v2[i].first - v2[j].first;

          ans = binarySearch(target, v2[i].second, v2[j].second, v2);

          if (ans!=-1) {
            cout << v2[i].second+1 << " "<< v2[j].second+1 << " "<< v2[ans].second+1 << ln;
            return 0;
          }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}