#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N;
    cin >> H >> W >> N;
    vector hasHole(H + 1, vector<bool>(W + 1, false));
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        hasHole[a][b] = true;
    }

    ll res = 0;
    vector dp(H + 1, vector<ll>(W + 1, 0));
    for (int i = 1; i < H + 1; ++i) {
        for (int j = 1; j < W + 1; ++j) {
            if (hasHole[i][j])
                dp[i][j] = 0;
            else {
                dp[i][j] =
                    min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            }
            res += dp[i][j];
        }
    }

        cout << res << endl;
    return 0;
}
