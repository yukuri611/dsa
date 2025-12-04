#include <algorithm>
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
template <typename T>
bool chmax(T& a, T b) {
    if (a < b) {
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
    vector<ll> dp(W_max + 1, 0);  // dp[i] = 0 ~ i -1までの荷物

    rep(i, N) {
        int w = W[i], v = V[i];

        for (int j = W_max; j >= W[i]; --j) {
            chmax(dp[j], dp[j - W[i]] + V[i]);
        }
    }

    cout << dp[W_max] << endl;
    return 0;
}
