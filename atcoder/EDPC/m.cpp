#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <typename T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int mod = 1e9 + 7;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> dp(K + 1);
    dp[K] = 1;
    rep(i, N) {
        vector<int> nextDp(K + 1);
        rep(j, K + 1) {
            nextDp[j] = dp[min(K, j + A[i])];
            if (j > 0) nextDp[j] = (nextDp[j] - dp[j - 1] + mod) % mod;
        }
        rep(j, K) {
            nextDp[j + 1] += nextDp[j];
            nextDp[j + 1] %= mod;
        }
        dp = nextDp;
    }
    cout << dp[0] << endl;
    return 0;
}
