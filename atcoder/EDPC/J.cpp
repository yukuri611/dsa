#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<vector<double>>> dp;
int N;
vector<int> A;

void dfs(int i, int j, int k) {
    if (i > 0 && dp[i - 1][j][k] == -1) dfs(i - 1, j, k);
    if (j > 0 && dp[i + 1][j - 1][k] == -1) dfs(i + 1, j - 1, k);
    if (k > 0 && dp[i][j + 1][k - 1] == -1) dfs(i, j + 1, k - 1);

    double e1 = 0, e2 = 0, e3 = 0;
    if (i > 0) e1 = dp[i - 1][j][k];
    if (j > 0) e2 = dp[i + 1][j - 1][k];
    if (k > 0) e3 = dp[i][j + 1][k - 1];
    dp[i][j][k] = (i * e1 + j * e2 + k * e3 + N) / (i + j + k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    int c1 = 0, c2 = 0, c3 = 0;
    rep(i, N) {
        if (A[i] == 1)
            c1++;
        else if (A[i] == 2)
            c2++;
        else
            c3++;
    }

    dp.resize(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, -1)));
    dp[0][0][0] = 0;
    dfs(c1, c2, c3);

    cout << fixed << setprecision(9) << dp[c1][c2][c3] << endl;
    return 0;
}
