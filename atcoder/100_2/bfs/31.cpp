#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<int>> dr = {{-1, 0, 1, 1, 0, -1}, {-1, 0, 1, 1, 0, -1}};
vector<vector<int>> dc = {{0, 1, 0, -1, -1, -1}, {1, 1, 1, 0, -1, 0}};

bool isInside(int r, int c, const vector<vector<int>>& G) {
    int H = G.size(), W = G[0].size();
    return (r >= 0 && r < H && c >= 0 && c < W);
}

void dfs(int r, int c, const vector<vector<int>>& G,
         vector<vector<bool>>& visited, int& res) {
    rep(i, 6) {
        int nr = r + dr[r % 2][i], nc = c + dc[r % 2][i];
        if (!isInside(nr, nc, G)) continue;
        if (visited[nr][nc]) continue;
        if (G[nr][nc] == 1)
            res++;
        else {
            visited[nr][nc] = true;
            dfs(nr, nc, G, visited, res);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    cin >> W >> H;
    vector<vector<int>> G(H + 2, vector<int>(W + 2));
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> G[i][j];
        }
    }

    rep(i, W + 2) {
        G[0][i] = 0;
        G[H + 1][i] = 0;
    }
    rep(i, H + 2) {
        G[i][0] = 0;
        G[i][W + 1] = 0;
    }

    int res = 0;
    vector<vector<bool>> visited(H + 2, vector<bool>(W + 2, false));
    visited[0][0] = true;
    dfs(0, 0, G, visited, res);

    cout << res << endl;
    return 0;
}
