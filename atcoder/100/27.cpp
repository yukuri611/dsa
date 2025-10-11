#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<int>> G;
vector<vector<bool>> visited;
int H, W;

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

int dfs(int r, int c) {
    int res = 0;
    visited[r][c] = true;
    rep(i, 4) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if (visited[nr][nc]) continue;
        if (G[nr][nc] == 0) continue;
        res = max(res, dfs(nr, nc));
    }
    visited[r][c] = false;
    return res + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> H;
    G.resize(H, vector<int>(W));
    rep(i, H) { rep(j, W) cin >> G[i][j]; }

    visited.resize(H, vector<bool>(W));
    int res = 0;
    rep(i, H) {
        rep(j, H) {
            if (G[i][j] == 1) {
                res = max(res, dfs(i, j));
            }
        }
    }

    cout << res << endl;
    return 0;
}
