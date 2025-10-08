#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int M = 5001;
    vector<vector<int>> cnts(M, vector<int>(M, 0));
    rep(i, N) {
        int a = A[i]; int b = B[i];
        cnts[a][b]++;
    }

    vector<vector<int>> sum(M + 1, vector<int>(5002, 0));
    rep(i, M) {
        rep(j, M) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + cnts[i][j];
        }
    }

    int res = 0;
    for (int minH = 1; minH < M - K; ++minH) {
        for (int minW = 1; minW < M - K; ++minW) {
            int maxH = minH + K; int maxW = minW + K;
            int cnt = sum[maxH + 1][maxW + 1] - sum[maxH + 1][minW] - sum[minH][maxW + 1] + sum[minH][minW];
            res = max(res, cnt);
        }
    }

    cout << res << endl;
    return 0;
}
