#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

int main() {
    int K;
    cin >> K;
    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(K + 1, 0);
    int s = 0;
    dp[0] = 0;
    for (int i = 1; i <= 9; ++i) {
        dp[i] = 1 + s;
        s += dp[i];
    }

    for (int i = 10; i <= K; ++i) {
        for (int j = 1; j < 10; ++j) {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }

    cout << dp[K] << endl;
    return 0;
}
