#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};

int bfs(int sx, int sy, int gx, int gy, vector<string>& G) {
    int H = G.size();
    int W = G[0].size();
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (dist[nr][nc] != -1) continue;
            if (G[nr][nc] == 'X') continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return dist[gx][gy];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N;
    cin >> H >> W >> N;
    vector<string> G(H);
    rep(i, H) { cin >> G[i]; }

    int si, sj;
    vector<pair<int, int>> factory_grid(N + 1);
    rep(i, H) {
        rep(j, W) {
            if (G[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (G[i][j] >= '1' && G[i][j] <= '9') {
                int factory_index = G[i][j] - '0';
                factory_grid[factory_index] = {i, j};
            }
        }
    }
    factory_grid[0] = {si, sj};

    int res = 0;
    rep(i, N) {
        auto [sx, sy] = factory_grid[i];
        auto [gx, gy] = factory_grid[i + 1];
        int dist = bfs(sx, sy, gx, gy, G);
        res += dist;
    }

    cout << res << endl;
    return 0;
}
