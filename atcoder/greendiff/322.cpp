#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, P;
    cin >> N >> K >> P;

    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K));
    rep(i, N) {
        cin >> C[i];
        rep(j, K) cin >> A[i][j];
    }

    int M = 1;
    rep(i, K) { M *= (P + 1); }

    vector<ll> dp(M, LLONG_MAX);
    dp[0] = 0;

    rep(i, N) {
        auto nextDp = dp;
        rep(s, M) {
            if (dp[s] == LLONG_MAX) continue;
            vector<int> cnt(K, 0);
            int curr = s;
            rep(j, K) {
                cnt[j] = curr % (P + 1);
                curr /= (P + 1);
            }
            rep(j, K) {
                cnt[j] += A[i][j];
                cnt[j] = min(cnt[j], P);
            }
            int newS = 0;
            curr = 1;
            rep(j, K) {
                newS += curr * cnt[j];
                curr *= (P + 1);
            }
            if (nextDp[newS] > dp[s] + C[i]) {
                nextDp[newS] = dp[s] + C[i];
            }
        }
        dp = nextDp;
    }
    if (dp[M - 1] == LLONG_MAX) dp[M - 1] = -1;
    cout << dp[M - 1] << endl;
    return 0;
}
