#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    multiset<ll> ms;
    set<ll> s;

    forn(i, 0, n) cin >> v[i];

    ll i = 0, j = 0;
    ll ans = 0;

    while (j < n) {
        ms.insert(v[j]);
        s.insert(v[j]);
        j++;

        while (s.size() > k) {
            ms.erase(ms.find(v[i]));
            if (ms.count(v[i]) == 0) {
                s.erase(v[i]);
            }
            i++;
        }
        ans += (j - i);
    }

    cout << ans << ln;
    return 0;
}