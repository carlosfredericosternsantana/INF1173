#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// int main() {
//     _;
//     return 0;
// }
int main() 
{
    _;
    int n , x ; 
    vector<int> v ;
    vector<int> out ; 
    cin >> n >> x ; 
    
    forn(i,0,n) {
      int inpt ; 
      cin >> inpt ; 
      v.push_back(inpt);
    }
    forn(i,0,n) {
      if (x > v[i]) {
        x = v[i];
        out.push_back(1);
      }
      else 
        out.push_back(0);
      
    }
    forn(i,0,n) 
      cout << out[i] << '\n';
    
    return 0;
}