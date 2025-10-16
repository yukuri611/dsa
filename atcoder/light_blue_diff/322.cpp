#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int N = 4;
vector visited(N, vector<bool>(N, false));
vector<vector<string>> Ps;

void rotate(vector<string> &P) {
    vector<string> res = P;
    rep(r, N) {
        rep(c, N) { res[c][N - 1 - r] = P[r][c]; }
    }
    P = res;
}

bool is_inside(int r, int c) { return (r >= 0 && r < N && c >= 0 && c < N); }

bool canFit(int r, int c, vector<string> &P, vector<vector<bool>> &grid) {
    rep(i, N) {
        rep(j, N) {
            if (P[i][j] == '#') {
                int r_on_grid = i + r;
                int c_on_grid = j + c;
                if (!is_inside(r_on_grid, c_on_grid)) return false;
                if (grid[r_on_grid][c_on_grid]) return false;
            }
        }
    }
    return true;
}

void fillGrid(int r, int c, const vector<string> &P,
              vector<vector<bool>> &grid) {
    rep(i, N) {
        rep(j, N) {
            if (P[i][j] == '#' && is_inside(r + i, c + j))
                grid[r + i][c + j] = true;
        }
    }
}

void removeGrid(int r, int c, const vector<string> &P,
                vector<vector<bool>> &grid) {
    rep(i, N) {
        rep(j, N) {
            if (P[i][j] == '#' && is_inside(r + i, c + j))
                grid[r + i][c + j] = false;
        }
    }
}

bool dfs(int k, vector<vector<bool>> &grid) {
    if (k == 3) {
        bool ok = 1;
        rep(i, 4) rep(j, 4) ok &= grid[i][j];
        return ok;
    }
    rep(d, 4) {
        for (int i = -N + 1; i < N; ++i) {
            for (int j = -N + 1; j < N; ++j) {
                if (canFit(i, j, Ps[k], grid)) {
                    fillGrid(i, j, Ps[k], grid);
                    if (dfs(k + 1, grid)) {
                        return true;
                    }
                    removeGrid(i, j, Ps[k], grid);
                }
            }
        }
        rotate(Ps[k]);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Ps.resize(3, vector<string>(N));
    rep(i, N) cin >> Ps[0][i];
    rep(i, N) cin >> Ps[1][i];
    rep(i, N) cin >> Ps[2][i];

    vector<vector<bool>> grid(N, vector<bool>(N, false));
    bool res = dfs(0, grid);
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
