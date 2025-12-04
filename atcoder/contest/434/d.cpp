#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> U(N), D(N), L(N), R(N);
    rep(i, N) { cin >> U[i] >> D[i] >> L[i] >> R[i]; }

    int M = 2000;

    // imos法
    vector<vector<int>> S(M + 2, vector<int>(M + 2, 0));
    rep(i, N) {
        int u = U[i], d = D[i], l = L[i], r = R[i];
        S[u][l]++;
        S[u][r + 1]--;
        S[d + 1][l]--;
        S[d + 1][r + 1]++;
    }
    rep(i, M + 1) rep(j, M + 2) S[i + 1][j] += S[i][j];
    rep(i, M + 2) rep(j, M + 1) S[i][j + 1] += S[i][j];

    // 累積和で1のマスを数える
    vector<vector<int>> cnt_one(M + 2, vector<int>(M + 2, 0));
    for (int i = 1; i < M + 2; ++i) {
        for (int j = 1; j < M + 2; ++j) {
            cnt_one[i][j] =
                cnt_one[i - 1][j] + cnt_one[i][j - 1] - cnt_one[i - 1][j - 1];
            if (S[i][j] == 1) cnt_one[i][j]++;
        }
    }

    int total_not_cover_cnt = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (S[i][j] == 0) total_not_cover_cnt++;
        }
    }

    rep(i, N) {
        int u = U[i], d = D[i], l = L[i], r = R[i];
        int curr_cnt_one = cnt_one[d][r] - cnt_one[d][l - 1] -
                           cnt_one[u - 1][r] + cnt_one[u - 1][l - 1];
        cout << total_not_cover_cnt + curr_cnt_one << endl;
    }
    return 0;
}
