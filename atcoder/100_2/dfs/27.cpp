#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dh = {1, 0, -1, 0};
vector<int> dw = {0, 1, 0, -1};
bool isInside(int h, int w, const vector<vector<int>>& A) {
    int H = A.size();
    int W = A[0].size();
    return (h >= 0 && h < H && w >= 0 && w < W);
}
int dfs(int h, int w, const vector<vector<int>>& A,
        vector<vector<bool>>& visited) {
    int max_length = 0;
    rep(i, 4) {
        int nh = h + dh[i], nw = w + dw[i];
        if (isInside(nh, nw, A)) {
            if (A[nh][nw] == 1 && !visited[nh][nw]) {
                visited[nh][nw] = true;
                max_length = max(max_length, dfs(nh, nw, A, visited));
                visited[nh][nw] = false;
            }
        }
    }

    return max_length + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) { cin >> A[i][j]; }
    }

    int res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    rep(i, n) {
        rep(j, m) {
            if (A[i][j] == 1) {
                visited[i][j] = true;
                res = max(res, dfs(i, j, A, visited));
                visited[i][j] = false;
            }
        }
    }

    cout << res << endl;
    return 0;
}
