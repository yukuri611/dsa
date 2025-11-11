#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {-1, 1, 0, 0};  // up, down, right, left
vector<int> dc = {0, 0, 1, -1};

bool isInside(int r, int c, vector<vector<vector<int>>>& G) {
    int H = G.size();
    int W = G[0].size();
    return (r >= 0 && r < H && c >= 0 && c < W);
}

int solve(int sr, int sc, int gr, int gc, vector<vector<vector<int>>>& G) {
    int H = G.size();
    int W = G[0].size();
    vector<vector<int>> dist(H, vector<int>(W, 0));
    dist[sr][sc] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!isInside(nr, nc, G)) continue;
            if (dist[nr][nc] != 0) continue;
            if (G[nr][nc][i] == 1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return dist[gr][gc];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> res_list;
    while (true) {
        int H, W;
        cin >> W >> H;
        if (H == 0 && W == 0) break;
        vector<vector<vector<int>>> G(H,
                                      vector<vector<int>>(W, vector<int>(4)));
        // down, up, left, right
        rep(i, 2 * H - 1) {
            if (i % 2 == 0) {
                rep(j, W - 1) {
                    int wall;
                    cin >> wall;
                    G[i / 2][j][3] = wall;
                    G[i / 2][j + 1][2] = wall;
                }
            } else {
                rep(j, W) {
                    int wall;
                    cin >> wall;
                    G[i / 2][j][0] = wall;
                    G[i / 2 + 1][j][1] = wall;
                }
            }
        }

        int res = solve(0, 0, H - 1, W - 1, G);

        res_list.push_back(res);
    }
    for (int res : res_list) cout << res << endl;

    return 0;
}
