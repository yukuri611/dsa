#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;
    int gx, gy;
    cin >> gx >> gy;
    gx--;
    gy--;

    vector<string> G(R);
    rep(i, R) { cin >> G[i]; }

    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        rep(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (G[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[gx][gy] << endl;
    return 0;
}
