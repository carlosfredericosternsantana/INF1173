#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

bool compare(pair<ll,ll>& p1, pair<ll,ll>& p2) {
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n; 
    ll out = 0; 
    ll last = 0;
    
    vector<pair<ll,ll>> v;
    cin >> n;
    
    forn(i,0,n) {
        ll first, second;
        cin >> first >> second;
        v.push_back({first, second});
    }

    sort(v.begin(), v.end(), compare);

    forn(i,0,n) {
        if (v[i].first >= last) {
            last = v[i].second;
            out++;
        }
    }

    cout << out << ln;
}