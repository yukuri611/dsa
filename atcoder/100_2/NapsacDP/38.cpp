#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> res_list(N);

    rep(i, N) {
        string X, Y;
        cin >> X >> Y;
        int S = X.size();
        int T = Y.size();

        vector<vector<int>> dp(S + 1, vector<int>(T + 1, 0));
        for (int j = 1; j < S + 1; ++j) {
            for (int k = 1; k < T + 1; ++k) {
                char x = X[j - 1], y = Y[k - 1];
                if (x == y) dp[j][k] = dp[j - 1][k - 1] + 1;
                dp[j][k] = max({dp[j][k], dp[j - 1][k], dp[j][k - 1]});
            }
        }

        res_list[i] = dp[S][T];
    }
    rep(i, N) cout << res_list[i] << endl;
    return 0;
}
