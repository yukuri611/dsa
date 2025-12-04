#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int mod = 1e9 + 7;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> G[i][j];

    // bit DP
    vector<int> dp((1 << N), 0);
    dp[0] = 1;
    rep(s, (1 << N)) {
        rep(d, N) {
            if (!(s & (1 << d)) && G[__popcount(s)][d] == 1) {
                int newS = s | (1 << d);
                dp[newS] = (dp[newS] + dp[s]) % mod;
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
