#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int N = 4;
vector visited(N, vector<bool>(N, false));

vector<string> rotate(vector<string> &P, int d) {
    vector<string> curr = P;
    rep(i, d) {
        vector<string> temp = curr;
        rep(r, N) {
            rep(c, N) { temp[r][c] = curr[c][N - 1 - r]; }
        }
        curr = temp;
    }
    return curr;
}

bool is_inside(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

bool canfill(int index, int d, vector<string> &P, vector<vector<bool>> &grid) {
    auto rotateP = rotate(P, d);

    int r_base = index / N;
    int c_base = index % N;

    rep(i, N) {
        rep(j, N) {
            if (rotateP[i][j] == '.') continue;
            int r_on_grid = i + r_base;
            int c_on_grid = j + c_base;
            if (!is_inside(r_on_grid, c_on_grid)) return false;
            if (grid[r_on_grid][c_on_grid]) return false;
        }
    }
    rep(i, N) {
        rep(j, N) {
            if (rotateP[i][j] == '#') {
                int r_on_grid = i + r_base;
                int c_on_grid = j + c_base;
                grid[r_on_grid][c_on_grid] = true;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> P1(N), P2(N), P3(N);
    rep(i, N) cin >> P1[i];
    rep(i, N) cin >> P2[i];
    rep(i, N) cin >> P3[i];

    // ポリオミノの総ブロック数を数える
    int total_blocks = 0;
    vector<vector<string>> Ps = {P1, P2, P3};
    for (const auto &p : Ps) {
        rep(r, N) rep(c, N) if (p[r][c] == '#') total_blocks++;
    }
    // 総ブロック数が16でなければ敷き詰め不可能
    if (total_blocks != N * N) {
        cout << "No" << endl;
        return 0;
    }

    rep(i1, N * N) {
        rep(d1, 4) {
            vector<vector<bool>> grid1(N, vector<bool>(N, false));
            if (!canfill(i1, d1, P1, grid1)) continue;
            rep(i2, N * N) {
                rep(d2, 4) {
                    vector<vector<bool>> grid2 = grid1;
                    if (!canfill(i2, d2, P2, grid2)) continue;
                    rep(i3, N * N) {
                        rep(d3, 4) {
                            vector<vector<bool>> grid3 = grid2;
                            if (!canfill(i3, d3, P3, grid3)) continue;
                            bool valid = true;
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
