#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<int> X1(n), Y1(n), X2(n), Y2(n);
    rep(i, n) { cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i]; }

    // 座圧
    vector<int> X, Y;
    rep(i, n) {
        X.push_back(X1[i]);
        X.push_back(X2[i]);
        Y.push_back(Y1[i]);
        Y.push_back(Y2[i]);
    }
    X.push_back(0);
    X.push_back(w);
    Y.push_back(0);
    Y.push_back(h);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    int sx = X.size(), sy = Y.size();

    // imos
    vector<vector<int>> S(sx, vector<int>(sy));
    rep(i, n) {
        int x1 = lower_bound(X.begin(), X.end(), X1[i]) - X.begin();
        int x2 = lower_bound(X.begin(), X.end(), X2[i]) - X.begin();
        int y1 = lower_bound(Y.begin(), Y.end(), Y1[i]) - Y.begin();
        int y2 = lower_bound(Y.begin(), Y.end(), Y2[i]) - Y.begin();
        S[x1][y1]++;
        S[x2][y1]--;
        S[x1][y2]--;
        S[x2][y2]++;
    }
    rep(i, sx - 1) rep(j, sy) S[i + 1][j] += S[i][j];
    rep(i, sx) rep(j, sy - 1) S[i][j + 1] += S[i][j];

    // bfsで区切られた領域を求める
    int ans = 0;
    vector<vector<bool>> visited(sx - 1, vector<bool>(sy - 1));
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    rep(i, sx - 1) {
        rep(j, sy - 1) {
            if (visited[i][j]) continue;
            if (S[i][j]) continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                rep(k, 4) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= sx - 1 || ny < 0 || ny >= sy - 1)
                        continue;
                    if (S[nx][ny]) continue;
                    if (visited[nx][ny]) continue;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
