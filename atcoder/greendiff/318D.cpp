#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<ll>> G(N, vector<ll>(N));
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            int d;
            cin >> d;
            G[i][j] = d;
            G[j][i] = d;
        }
    }

    vector<ll> dp((1 << N), 0);

    rep(s, (1 << N)) {
        if (__builtin_popcount(s) % 2) continue;
        vector<int> notUsed;
        rep(j, N) {
            if (!((s >> j) & 1)) notUsed.push_back(j);
        }

        rep(j, notUsed.size()) {
            for (int k = j + 1; k < notUsed.size(); ++k) {
                int newS = s | (1 << j) | (1 << k);
                dp[newS] = max(dp[newS], dp[s] + G[j][k]);
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
