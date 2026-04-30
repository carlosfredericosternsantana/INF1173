#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

struct DSU {
    vector<ll> parents;
    vector<ll> rank; 

    public: DSU (ll size) {
        parents.resize(size);
        rank.assign(size, 1); // Inicializa o rank para não dar SegFault
        forn(i,0,size)
            parents[i]=i;
    }

    ll find(ll node){
        if (parents[node]!=node) {
            parents[node]=find(parents[node]);
        }
        return parents[node];
    }

    // "Union" com U maiúsculo para não conflitar com a keyword do C++
    void Union (ll node1 , ll node2) {
        ll p1 = find(node1);
        ll p2 = find(node2);
        if (p1!=p2) {
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
    set<ll> s; 
    
    forn(i,0,k) {
        ll a, b;
        cin >> a >> b;
        dsu.Union(--a, --b);
    }

    
    forn(i, 0, n) 
      dsu.find(i);

    for (ll node : dsu.parents)
        s.emplace(node);

    cout << s.size()-1 << ln;

    if (!s.empty()) {
        ll p1 = *s.begin();
        for(ll node : s)
            if(node != p1)
                cout << p1+1 << " " << node+1 << ln;
    }

    return 0;
}