#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dh = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dw = {0, 1, 0, -1, 1, -1, 1, -1};

bool isInside(int h, int w, vector<vector<int>> C) {
    int H = C.size();
    int W = C[0].size();
    return (h >= 0 && h < H && w >= 0 && w < W);
}

void solve(int h, int w, const vector<vector<int>>& C,
           vector<vector<bool>>& visited, stack<pair<int, int>>& s) {
    visited[h][w] = true;
    rep(i, 8) {
        int nh = h + dh[i], nw = w + dw[i];
        if (isInside(nh, nw, C)) {
            if (C[nh][nw] == 1 && !visited[nh][nw]) s.push({nh, nw});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> res_list;
    while (true) {
        int W, H;
        cin >> W >> H;
        if (H == 0 && W == 0) break;
        vector<vector<int>> C(H, vector<int>(W));
        rep(i, H) { rep(j, W) cin >> C[i][j]; }

        vector<vector<bool>> visited(H, vector<bool>(W, false));

        ll res = 0;
        rep(i, H) {
            rep(j, W) {
                if (C[i][j] && !visited[i][j]) {
                    res++;
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    while (!s.empty()) {
                        auto [h, w] = s.top();
                        s.pop();
                        solve(h, w, C, visited, s);
                    }
                }
            }
        }
        res_list.push_back(res);
    }

    for (int res : res_list) cout << res << endl;
    return 0;
}
