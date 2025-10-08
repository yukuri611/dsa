#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int N = S.size();

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    rep(i, N) {
        vector<int> nextDp(N + 1, 0);
        rep(j, N) {
            if (S[i] != ')') {
                nextDp[j + 1] += dp[j];
                nextDp[j + 1] %= mod;
            }
            if (S[i] != '(') {
                nextDp[j] += dp[j + 1];
                nextDp[j] %= mod;
            }
        }
        dp = nextDp;
    }

    cout << dp[0] << endl;
    return 0;
}
