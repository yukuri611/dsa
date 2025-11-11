#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};

bool isInside(int r, int c, int H, int W) {
    return (r >= 0 && r < H && c >= 0 && c < W);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) { cin >> S[i]; }

    vector<vector<int>> dist(H, vector<int>(W, 0));
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!isInside(nr, nc, H, W)) continue;
            if (S[nr][nc] == '#') continue;
            if (dist[nr][nc] == 0) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    if (dist[H - 1][W - 1] == 0) {
        cout << -1 << endl;
        return 0;
    }

    int cnt_wall = 0;
    rep(i, H) rep(j, W) if (S[i][j] == '#') cnt_wall++;

    int res = H * W - cnt_wall - dist[H - 1][W - 1];
    cout << res << endl;
    return 0;
}
