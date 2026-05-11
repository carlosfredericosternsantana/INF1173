#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
#define vll vector<ll> 
#define INF 1e18

vll dx = {1,-1,0,0};
vll dy = {0,0,1,-1};
vector<char> dir = {'D','U','R','L'};

string reconstruct_path(pair<ll,ll> start, pair<ll,ll> end,
                       vector<vector<pair<ll,ll>>>& parent,
                       vector<vector<char>>& move_dir) {
    
    string path = "";
    pair<ll,ll> cur = end;
    
    while (cur != start) {
        path += move_dir[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }
    
    reverse(path.begin(), path.end());
    return path;
}

void bfs_monsters(vector<vector<char>>& grid,
                  vector<vll>& distM,
                  ll n, ll m,
                  vector<pair<ll,ll>>& monsters) {

    queue<pair<ll,ll>> q;

    for (auto mpos : monsters) {
        q.push(mpos);
        distM[mpos.first][mpos.second] = 0;
    }

    while (!q.empty()) {
        auto next = q.front(); 
        q.pop();

        forn(i,0,4) {
            if (next.first + dx[i] >= 0 && next.first + dx[i] < n &&
                next.second + dy[i] >= 0 && next.second + dy[i] < m) {

                if (grid[next.first + dx[i]][next.second + dy[i]] != '#' &&
                    distM[next.first + dx[i]][next.second + dy[i]] == INF) {

                    distM[next.first + dx[i]][next.second + dy[i]] =
                        distM[next.first][next.second] + 1;

                    q.push({next.first + dx[i], next.second + dy[i]});
                }
            }
        }
    }
}

bool bfs_player(vector<vector<char>>& grid, vector<vll>& distM, vector<vll>& distA, pair<ll,ll>& start, pair<ll,ll>& exit_cell, vector<vector<pair<ll,ll>>>& parent, vector<vector<char>>& move_dir, ll n, ll m) {

    queue<pair<ll,ll>> q;
    q.push(start);
    distA[start.first][start.second] = 0;

    if (start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1) {
        exit_cell = start;
        return true;
    }

    while (!q.empty()) {
        auto next = q.front(); 
        q.pop();

        forn(i,0,4) {
            if (next.first + dx[i] >= 0 && next.first + dx[i] < n &&
                next.second + dy[i] >= 0 && next.second + dy[i] < m) {

                if (grid[next.first + dx[i]][next.second + dy[i]] == '#')
                    continue;

                if (distA[next.first + dx[i]][next.second + dy[i]] == INF) {

                    if (distA[next.first][next.second] + 1 <
                        distM[next.first + dx[i]][next.second + dy[i]]) {

                        distA[next.first + dx[i]][next.second + dy[i]] =
                            distA[next.first][next.second] + 1;

                        parent[next.first + dx[i]][next.second + dy[i]] = next;
                        move_dir[next.first + dx[i]][next.second + dy[i]] = dir[i];

                        q.push({next.first + dx[i], next.second + dy[i]});

                        if (next.first + dx[i] == 0 ||
                            next.first + dx[i] == n-1 ||
                            next.second + dy[i] == 0 ||
                            next.second + dy[i] == m-1) {

                            exit_cell = {next.first + dx[i], next.second + dy[i]};
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    forn(i,0,n)
        forn(j,0,m)
            cin >> grid[i][j];

    vector<vll> distM(n, vll(m, INF));
    vector<vll> distA(n, vll(m, INF));

    vector<vector<pair<ll,ll>>> parent(n, vector<pair<ll,ll>>(m, {-1,-1}));
    vector<vector<char>> move_dir(n, vector<char>(m));

    vector<pair<ll,ll>> monsters;
    pair<ll,ll> start;

    forn(i,0,n) {
        forn(j,0,m) {
            if (grid[i][j] == 'M') monsters.push_back({i,j});
            if (grid[i][j] == 'A') start = {i,j};
        }
    }

    bfs_monsters(grid, distM, n, m, monsters);

    pair<ll,ll> exit_cell;
    bool ok = bfs_player(grid, distM, distA, start, exit_cell,
                         parent, move_dir, n, m);

    if (ok) {
        string path = reconstruct_path(start, exit_cell, parent, move_dir);

        cout << "YES" << ln;
        cout << path.size() << ln;
        cout << path << ln;
    } else {
        cout << "NO" << ln;
    }

    return 0;
}