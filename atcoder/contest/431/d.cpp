#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> W(N), H(N), B(N);
    rep(i, N) { cin >> W[i] >> H[i] >> B[i]; }

    int M = 500001;

    vector<ll> dp(M, -1);  // weight diff(body - head): value
    int offset = 250000;
    dp[0 + offset] = 0;
    rep(i, N) {
        vector<ll> nextDp(M, -1);
        int w = W[i], h = H[i], b = B[i];
        for (int i = 0; i + w < M; ++i) {
            if (dp[i] != -1 && i - w > -1)
                nextDp[i - w] = max(nextDp[i - w], dp[i] + h);
            if (dp[i] != -1) nextDp[i + w] = max(nextDp[i + w], dp[i] + b);
        }
        dp = nextDp;
    }

    ll res = 0;
    for (int i = offset; i < 500001; ++i) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
