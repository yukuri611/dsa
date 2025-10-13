#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int N, K, P;
vector<int> calc(int a) {
    vector<int> res(K, 0);
    rep(i, K) {
        res[i] = a % (P + 1);
        a /= (P + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> P;
    vector<vector<int>> A(N, vector<int>(K));
    vector<ll> C(N);
    rep(i, N) {
        cin >> C[i];
        rep(j, K) { cin >> A[i][j]; }
    }

    int M = pow(P + 1, K);
    vector<ll> dp(M, LLONG_MAX);
    dp[0] = 0;
    rep(i, N) {
        vector<ll> nextDp = dp;
        rep(j, M) {
            if (dp[j] == LLONG_MAX) continue;
            vector<int> curr_cnt = calc(j);
            vector<int> next_cnt(K);
            rep(k, K) { next_cnt[k] = min(curr_cnt[k] + A[i][k], P); }

            int nj = 0;
            int curr = 1;
            rep(k, K) {
                nj += next_cnt[k] * curr;
                curr *= (P + 1);
            }

            nextDp[nj] = min(nextDp[nj], dp[j] + C[i]);
        }
        dp = nextDp;
    }

    if (dp[M - 1] == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << dp[M - 1] << endl;
    return 0;
}
