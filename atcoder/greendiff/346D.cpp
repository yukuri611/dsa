// dp[i + 1][0] = dp[i][0] + (0にするために必要な手順に必要なコスト)
// dp[i + 1][1] = dp[i][0] + (1にするために必要な手順にかかるコスト) +

// dp[i + 1][0][0] =
// 初期値dp[0][0][S[0]] = 0;
// res = min(dp[N][1][0], dp[N][1][1]);

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> C(N);
    rep(i, N) cin >> C[i];

    vector<vector<vector<ll>>> dp(
        N, vector<vector<ll>>(2, vector<ll>(2, LLONG_MAX)));
    int digit = S[0] - '0';
    dp[0][0][digit] = 0;
    dp[0][0][1 - digit] = C[0];

    for (int i = 1; i < N; ++i) {
        int digit = S[i] - '0';
        dp[i][0][digit] = dp[i - 1][0][1 - digit];
        dp[i][0][1 - digit] = dp[i - 1][0][digit] + C[i];
        dp[i][1][digit] = min(dp[i - 1][1][1 - digit], dp[i - 1][0][digit]);
        dp[i][1][1 - digit] =
            min(dp[i - 1][1][digit], dp[i - 1][0][1 - digit]) + C[i];
    }

    ll res = min(dp[N - 1][1][0], dp[N - 1][1][1]);
    cout << res << endl;
    return 0;
}
