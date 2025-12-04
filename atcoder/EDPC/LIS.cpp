#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = -1;
    rep(i, n) {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        *it = A[i];
    }
    int ans = n;
    rep(i, n + 1) {
        if (dp[i] == INT_MAX) {
            ans = i - 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
