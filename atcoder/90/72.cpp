#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int H, W;
vector<string> C;
vector<vector<bool>> visited;

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

int dfs(int r, int c, int sr, int sc, int cnt) {
    if (r == sr && c == sc && cnt != 0) return cnt;
    if (visited[r][c]) return 0;
    visited[r][c] = true;
    int res = 0;
    rep(i, 4) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if (C[nr][nc] == '#') continue;
        res = max(res, dfs(nr, nc, sr, sc, cnt + 1));
    }
    visited[r][c] = false;
    return res;
}

int main() {
    cin >> H >> W;
    C.resize(H);
    rep(i, H) cin >> C[i];

    int res = 0;
    rep(i, H) {
        rep(j, W) {
            if (C[i][j] == '.') {
                visited.assign(H, vector<bool>(W, false));
                res = max(res, dfs(i, j, i, j, 0));
            }
        }
    }

    if (res < 3)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}
