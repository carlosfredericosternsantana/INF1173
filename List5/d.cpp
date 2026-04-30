#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

struct DSU {
    vector<ll> parents;
    vector<ll> rank; 
    ll components;
    ll gstComponentSize;

    public: DSU (ll size) {
        parents.resize(size);
        components = size;
        gstComponentSize = 1 ;
        rank.assign(size, 1); 
        forn(i,0,size)
            parents[i]=i;
    }

    ll find(ll node){
        if (parents[node]!=node) {
            parents[node]=find(parents[node]);
        }
        return parents[node];
    }

    void Union (ll node1 , ll node2) {
        ll p1 = find(node1);
        ll p2 = find(node2);
        if (p1!=p2) {
          components--;
          gstComponentSize = max(gstComponentSize,rank[p1]+rank[p2]);
            if (rank[p1]>rank[p2]) {
                parents[p2]=p1;
                rank[p1]+=rank[p2];
            }
            else {
                parents[p1] = p2;
                rank[p2]+=rank[p1];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k; 
    
    DSU dsu = DSU(n);
    vector<pair<ll,ll>> ans;
    forn(i,0,k) {
        ll a, b;
        cin >> a >> b;
        dsu.Union(--a, --b);
        ans.push_back(make_pair(dsu.components,dsu.gstComponentSize));
    }
    forn(i,0,ans.size())
      cout << ans[i].first << " " << ans[i].second << ln;
    return 0;
}