#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T;
    cin >> T;
    int N;
    cin >> N;

    int M = T.size();
    vector<int> dp(
        M + 1,
        INT_MAX);  // dp[i] = 0からi - 1文字まで埋まっているときの最小コスト。
    dp[0] = 0;
    rep(i, N) {
        int a;
        cin >> a;
        vector<string> S(a);
        rep(j, a) cin >> S[j];

        vector<int> nextDp = dp;
        rep(j, M) {
            if (dp[j] == INT_MAX) continue;
            for (int k = j + 1; k < M + 1; ++k) {
                string currS = T.substr(j, k - j);
                if (count(S.begin(), S.end(), currS)) {
                    nextDp[k] = min(nextDp[k], dp[j] + 1);
                }
            }
        }
        dp = nextDp;
    }
    if (dp[M] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[M] << endl;
    return 0;
}
