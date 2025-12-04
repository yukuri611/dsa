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
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    rep(i, N) dp[i][i] = 0;
    for (int len = 1; len <= N; ++len) {
        for (int l = 0; l + len <= N; ++l) {
            int r = l + len;
            ll pick_left = A[l] - dp[l + 1][r];
            ll pick_right = A[r - 1] - dp[l][r - 1];
            dp[l][r] = max(pick_left, pick_right);
        }
    }

    cout << dp[0][N] << endl;
    return 0;
}
