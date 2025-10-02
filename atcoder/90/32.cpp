#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    //入力
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    int M; cin >> M;
    vector<vector<int>> B(N, vector<int>(N, 0));
    rep(i, M) {
        int x, y; cin >> x >> y;
        x--; y--;
        B[x][y] = 1;
        B[y][x] = 1;
    }

    //計算
    vector<vector<int>> dp((1 << N), vector<int>(N, INT_MAX));
    rep(i, N) {
        dp[(1 << i)][i] = A[i][0];
    }
    
    for (int s = 1; s < (1 << N); ++s) {
        int c = __builtin_popcount(s); //次の走者が走る区間
        rep(i, N) {
            if (dp[s][i] == INT_MAX) continue;
            rep(j, N) {
                if (B[i][j]) continue; 
                if ((s >> j) & 1) continue;
                int nextS = s | (1 << j);
                dp[nextS][j] = min(dp[nextS][j], dp[s][i] + A[j][c]);
            }
        }
    }

    int res = INT_MAX;
    rep(j, N) res = min(res, dp[(1 << N) - 1][j]);
    if (res == INT_MAX) res = -1;
    cout << res << endl;
    return 0;

}
