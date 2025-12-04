#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<double> P(N);
    rep(i, N) { cin >> P[i]; }

    vector<vector<double>> dp(N + 1, vector<double>(N + 1));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, i + 2) {
            dp[i + 1][j] += dp[i][j] * (1 - P[i]);
            if (j > 0) dp[i + 1][j] += dp[i][j - 1] * P[i];
        }
    }

    double ans = 0;
    for (int i = (N + 1) / 2; i <= N; ++i) ans += dp[N][i];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
