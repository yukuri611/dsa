#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string K;
    cin >> K;
    int D;
    cin >> D;

    vector<vector<vector<ll>>> dp(K.size() + 1,
                                  vector<vector<ll>>(D, vector<ll>(2, 0)));
    dp[0][0][0] = 1;
    rep(i, K.size()) {
        int currNum = K[i] - '0';
        rep(j, D) {
            dp[i + 1][j][0] += dp[i][(j - currNum + 10 * D) % D][0];
            dp[i + 1][j][0] %= mod;
            rep(k, 10) dp[i + 1][j][1] += dp[i][(j - k + 10 * D) % D][1];
            rep(k, currNum) dp[i + 1][j][1] += dp[i][(j - k + 10 * D) % D][0];
            dp[i + 1][j][1] %= mod;
        }
    }

    cout << (dp[K.size()][0][0] + dp[K.size()][0][1] - 1 + mod) % mod << endl;
    return 0;
}
