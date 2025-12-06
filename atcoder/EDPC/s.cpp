#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
#define rep(i, n) for (int i = 0; i < n; ++i)

int mod = 1e9 + 7;

int main() {
    string K;
    cin >> K;
    int D;
    cin >> D;

    vector<mint> dp(D);
    int curr_sum = 0;
    rep(i, K.size()) {
        vector<mint> nextDp(D);
        int d = K[i] - '0';
        rep(j, d) { nextDp[(curr_sum + j) % D] += 1; }
        rep(j, D) {
            rep(k, 10) { nextDp[(j + k) % D] += dp[j]; }
        }
        curr_sum = (curr_sum + d) % D;
        dp = nextDp;
    }

    mint ans = dp[0];
    ans -= 1;

    if (curr_sum == 0) {
        ans += 1;
    }

    cout << ans.val() << endl;
    return 0;
}
