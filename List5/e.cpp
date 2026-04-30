#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ln "\n"
const ll mod = 1e9+7; //  escolhi o numero para marcar o visitado ou não , x >= mod -> x visitado e dist = x%mod

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir_char[] = {'D', 'U', 'R', 'L'};

void buildPath(pair<ll, ll> cur, pair<ll, ll> start, vector<vector<int>>& parent, string& path) {
    if (cur == start) 
      return;

    int d = parent[cur.first][cur.second];
    pair<ll, ll> prev = {cur.first - dx[d], cur.second - dy[d]};

    buildPath(prev, start, parent, path);
    
    path += dir_char[d];
}

bool bfs(pair<ll, ll> start, pair<ll, ll> target, int n, int m, vector<vector<ll>>& grid, vector<vector<int>>& parent) {
    queue<pair<ll, ll>> q;
    q.push(start);
    grid[start.first][start.second] = mod; // visited = true

    while (!q.empty()) {
        auto p = q.front(); 
        q.pop();
        if (p == target) 
          return true;
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] < mod) {
                grid[nx][ny] = mod;
                parent[nx][ny] = i;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m ;
    
    pair<ll, ll> start, target;
    vector<vector<ll>> grid(n, vector<ll>(m));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#') 
              grid[i][j] = mod;
            else {
                grid[i][j] = 0;
                if (c == 'A') 
                  start = {i, j};
                else if (c == 'B') 
                  target = {i, j};
            }
        }
    }

    if (bfs(start, target, n, m, grid, parent)) {
      cout << "YES" << ln;
      string finalPath = "";
      buildPath(target, start, parent, finalPath);
      cout << finalPath.length() << ln << finalPath << ln;
    } 
    else 
      cout << "NO" << ln;

    return 0;
}