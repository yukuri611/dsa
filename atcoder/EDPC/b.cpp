#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    rep(i, N) {
        for (int j = 1; j < K + 1 && i + j < N; ++j) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(H[i] - H[i + j]));
        }
    }

    cout << dp[N - 1] << endl;
    return 0;
}
