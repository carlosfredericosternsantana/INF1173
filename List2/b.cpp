#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

ll binarySearch(vector<pair<ll,ll>>& v, ll num, ll origin) {
    ll l = 0, r = v.size() - 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (v[mid].first == num) {
            if (v[mid].second != origin) return v[mid].second;
            if (mid > 0 && v[mid-1].first == num && v[mid-1].second != origin)
                return v[mid-1].second;
            if (mid < (ll)v.size()-1 && v[mid+1].first == num && v[mid+1].second != origin)
                return v[mid+1].second;
            return -1;
        }
        else if (v[mid].first < num) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

bool compare(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x;
    bool b = false;
    cin >> n >> x;
    vector<pair<ll,ll>> v;

    forn(i, 0, n) {
        ll inpt;
        cin >> inpt;
        v.push_back(make_pair(inpt, i));
    }

    sort(v.begin(), v.end(), compare);

    forn(i, 0, n) {
        ll ans = binarySearch(v, x - v[i].first, v[i].second);
        if (ans != -1) {
            b = true;
            cout << v[i].second + 1 << " " << ans + 1 << ln;
            break;
        }
    }

    if (!b) cout << "IMPOSSIBLE" << ln;

    return 0;
}