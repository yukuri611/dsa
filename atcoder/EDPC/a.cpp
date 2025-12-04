#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    if (N == 2) {
        cout << abs(H[1] - H[0]) << endl;
        return 0;
    }

    vector<int> dp(N, 0);
    dp[1] = abs(H[1] - H[0]);
    dp[2] = abs(H[2] - H[0]);
    for (int i = 2; i < N; ++i) {
        dp[i] = min(dp[i - 1] + abs(H[i - 1] - H[i]),
                    dp[i - 2] + abs(H[i - 2] - H[i]));
    }
    cout << dp[N - 1] << endl;
    return 0;
}
