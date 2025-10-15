#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    dp[0][1] = 1;
    rep(i, N - 1) {
        dp[i + 1][0] = dp[i][0] * (M - 2) + dp[i][1] * (M - 1);
        dp[i + 1][0] %= mod;
        dp[i + 1][1] = dp[i][0];
    }
    ll res = (dp[N - 1][0] * M) % mod;
    cout << res << endl;
    return 0;
}
