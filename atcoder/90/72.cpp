#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int ans = 0;
int H, W;
vector<string> S;
vector<vector<bool>> visited;
vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

void dfs(int sr, int sc, int r, int c, int d) {
    if (d != 0 && sr == r && sc == c) {
        ans = max(ans, d);
        return;
    }
    if (visited[r][c]) return;
    visited[r][c] = true;
    rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if (S[nr][nc] == '#') continue;
        dfs(sr, sc, nr, nc, d + 1);
    }
    visited[r][c] = false;
}

int main() {
    cin >> H >> W;
    S.resize(H);
    rep(i, H) cin >> S[i];
    rep(i, H) {
        rep(j, W) {
            visited.assign(H, vector<bool>(W, false));
            dfs(i, j, i, j, 0);
        }
    }
    if (ans <= 2)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
