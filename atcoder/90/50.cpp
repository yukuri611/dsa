#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
ll mod = 1e9 + 7;

int main() {
    int N, L;
    cin >> N >> L;
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    rep(i, N) {
        if (i + 1 < N + 1) dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        if (i + L < N + 1) dp[i + L] = (dp[i + L] + dp[i]) % mod;
    }
    cout << dp[N] << endl;
    return 0;
}
