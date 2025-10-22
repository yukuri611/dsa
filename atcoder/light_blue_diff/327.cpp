#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

double R(double A, int k) {
    double B = 0;
    double curr = 1;
    for (int i = 0; i < k; ++i) {
        B += curr;
        curr *= 0.9;
    }
    double C = 1200 / sqrt(k);
    return A / B - C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i < N + 1; ++i) cin >> P[i];

    vector<vector<double>> dp(N + 1, vector<double>(N + 1));
    dp[0][0] = 0;
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] * 0.9 + P[i]);
        }
        dp[i][i] = dp[i - 1][i - 1] * 0.9 + P[i];
    }

    double res = -1200;
    for (int k = 1; k < N + 1; ++k) {
        double A = dp[N][k];
        res = max(res, R(A, k));
    }

    cout << fixed << setprecision(6) << res << endl;
    return 0;
}
