#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int H, W;
vector<string> C;
vector<vector<bool>> visited;
vector<int> dr = {0,1,0,-1};
vector<int> dc = {1,0,-1,0};

int dfs(int sr, int sc, int r, int c) {
    visited[r][c] = true;
    int maximum = -1;
    rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if (nr == sr && nc == sc) {
            maximum = max(maximum, 0);
            continue;
        }
        if (visited[nr][nc]) continue;
        if (C[nr][nc] == '#') continue;
        int curr_d = dfs(sr, sc, nr, nc);
        if (curr_d == -1) continue;
        maximum = max(maximum, curr_d);
    }
    visited[r][c] = false;
    if (maximum == -1) return -1;
    else return maximum + 1;
}

int main() {
    //input
    cin >> H >> W;
    C.resize(H);
    rep(i, H) {
        cin >> C[i];
    }   
    visited.assign(H, vector<bool>(W, false));
    int ans = -1;
    rep(i, H) {
        rep(j, W) {
            if (C[i][j] == '.') {
                rep(k, H) rep(l, W) visited[k][l] = false;
                ans = max(ans, dfs(i, j, i, j));
            }
        }
    }
    if (ans < 3) {
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0;
}


