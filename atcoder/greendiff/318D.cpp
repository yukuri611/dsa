#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<ll>> G(N, vector<ll>(N, 0));
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) cin >> G[i][j];
    }

    vector<ll> dp((1 << N), 0);

    rep(s, (1 << N)) {
        int l = -1;
        rep(j, N) {
            if (!((s >> j) & 1)) {l = j; break;}
        }

        rep(j, N) {
            if (!(s >> j & 1)) {
                int ns = s | (1 << l) | (1 << j);
                dp[ns] = max(dp[ns], dp[s] + G[l][j]);
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    return 0;
}
