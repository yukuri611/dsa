#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1,false));
    dp[0][0] = true;
    for (int i = 0; i < N; ++i) {
        rep(j, S + 1) {
            if (dp[i][j]) {
                if (j+A[i] <= S) dp[i + 1][j + A[i]] = true;
                if (j+B[i] <= S)dp[i + 1][j + B[i]] = true;
            }
        }
    }

    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return 0;
    }

    string res;
    int remain = S;
    for (int i = N-1; i >= 0; --i) {
        if (remain - A[i] >= 0 && dp[i][remain - A[i]]) {
            res += 'A';
            remain -= A[i];
        }
        else {
            res += 'B';
            remain -= B[i];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;

}
