#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<bool> dp(K + 1, false);
    rep(i, K) {
        if (dp[i]) continue;
        rep(j, N) {
            if (i + A[j] < K + 1) dp[i + A[j]] = true;
        }
    }

    if (dp[K])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
