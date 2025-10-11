#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int M = 5000;
    vector<vector<int>> Cnt(M + 1, vector<int>(M + 1, 0));
    rep(i, N) {
        int a = A[i], b = B[i];
        Cnt[a][b]++;
    }
    for (int i = 1; i < M + 1; ++i) {
        for (int j = 1; j < M + 1; ++j) {
            Cnt[i][j] += Cnt[i - 1][j] + Cnt[i][j - 1] - Cnt[i - 1][j - 1];
        }
    }

    int res = 0;
    for (int minH = 1; minH < M - K + 1; ++minH) {
        for (int minW = 1; minW < M - K + 1; ++minW) {
            int maxH = minH + K, maxW = minW + K;
            int total_cnt = Cnt[maxH][maxW] - Cnt[maxH][minW - 1] -
                            Cnt[minH - 1][maxW] + Cnt[minH - 1][minW - 1];
            res = max(res, total_cnt);
        }
    }

    cout << res << endl;
    return 0;
}
