#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <typename T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N, W_max;
    cin >> N >> W_max;
    vector<int> W(N), V(N);
    rep(i, N) cin >> W[i] >> V[i];

    int M = 1e5;
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;
    rep(i, N) {
        int w = W[i], v = V[i];
        for (int j = M; j >= 0; --j) {
            if (dp[j] != INT_MAX && dp[j] + w <= W_max)
                chmin(dp[j + v], dp[j] + w);
        }
    }
    int ans = 0;
    for (int i = M; i >= 0; --i) {
        if (dp[i] != INT_MAX) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
