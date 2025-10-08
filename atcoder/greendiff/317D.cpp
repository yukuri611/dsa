#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

    int M = 0;
    rep(i, N) M += Z[i];

    vector<ll> dp(M + 1, INF);
    dp[0] = 0;
    rep(i, N) {
        int x = X[i], y = Y[i], z = Z[i];
        int cost = (X[i] > Y[i]) ? 0 : (x + y + 1) / 2 - x;
        for (int j = M; j >= z; --j) {
            dp[j] = min(dp[j], dp[j - Z[i]] + cost);
        }
    }

    ll res = INF;
    for (int i = (M + 1) / 2; i <= M; ++i) {
        res = min(res, dp[i]);
    }

    cout << res << endl;
    return 0;
}
