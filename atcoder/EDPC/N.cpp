#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> sumA(N + 1, 0);
    rep(i, N) { sumA[i + 1] = sumA[i] + A[i]; }

    // 区間DP
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LLONG_MAX));
    rep(i, N) dp[i][i + 1] = 0;
    for (int l = 2; l < N + 1; ++l) {
        for (int i = 0; i <= N - l; ++i) {
            int j = i + l;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] =
                    min(dp[i][j], dp[i][k] + dp[k][j] + (sumA[j] - sumA[i]));
            }
        }
    }

    cout << dp[0][N] << endl;
    return 0;
}
