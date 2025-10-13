#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<char>> dp(N, vector<char>(S + 1, '#'));
    if (A[0] <= S) dp[0][A[0]] = 'A';
    if (B[0] <= S) dp[0][B[0]] = 'B';

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < S + 1; ++j) {
            if (dp[i][j] != '#') {
                if (j + A[i + 1] < S + 1) dp[i + 1][j + A[i + 1]] = 'A';
                if (j + B[i + 1] < S + 1) dp[i + 1][j + B[i + 1]] = 'B';
            }
        }
    }

    if (dp[N - 1][S] == '#') {
        cout << "Impossible" << endl;
        return 0;
    }

    string res;
    int remain = S;
    for (int i = N - 1; i > -1; --i) {
        res += dp[i][remain];
        if (dp[i][remain] == 'A') {
            remain -= A[i];
        } else {
            remain -= B[i];
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
