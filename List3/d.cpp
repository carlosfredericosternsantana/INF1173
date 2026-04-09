#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    ll k;
    cin >> s >> k;

    ll i = 0, j = 0;
    ll cost = 0;
    ll ans = 0;

    while (j < s.size()) {
      
        if (s[j] == '.')  {
            if (cost < k)  {
                cost++;
                j++;
            } 
            else {
                if (s[i++] == '.') 
                  cost--;
            }
        } 
        else
            j++;
        ans = max(ans, j - i);
    }

    cout << ans << "\n";
    return 0;
}