#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
int mod = 1e9 + 7;
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    vector<int> dp(W + 1);
    dp[1] = 1;
    rep(i, H) {
        rep(j, W) {
            if (A[i][j] == '.') {
                dp[j + 1] += dp[j];
                dp[j + 1] %= mod;
            } else {
                dp[j + 1] = 0;
            }
        }
    }

    cout << dp[W] << endl;
    return 0;
}
