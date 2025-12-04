#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];
    rep(i, N - 1) {
        dp[i + 1][0] = max(dp[i][1], dp[i][2]) + A[i + 1];
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + B[i + 1];
        dp[i + 1][2] = max(dp[i][0], dp[i][1]) + C[i + 1];
    }
    cout << *(max_element(dp[N - 1].begin(), dp[N - 1].end())) << endl;
    return 0;
}
