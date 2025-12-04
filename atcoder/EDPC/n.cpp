#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <typename T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> sum(N + 1);
    rep(i, N) { sum[i + 1] += sum[i] + A[i]; }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LLONG_MAX));
    rep(i, N + 1) {
        dp[i][i] = 0;
        if (i < N) dp[i][i + 1] = 0;
    }
    for (int len = 2; len <= N; ++len) {
        for (int l = 0; l + len <= N; ++l) {
            int r = l + len;
            for (int mid = l + 1; mid <= r; ++mid) {
                chmin(dp[l][r], dp[l][mid] + dp[mid][r]);
            }
            dp[l][r] += sum[r] - sum[l];
        }
    }
    cout << dp[0][N] << endl;
    return 0;
}
