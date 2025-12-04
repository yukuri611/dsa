#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<vector<vector<double>>> dp;
int N;
int c1, c2, c3;
double dfs(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return 0;
    if (dp[i][j][k] > -0.5) return dp[i][j][k];

    double res = 0;
    if (k > 0) res += dfs(i, j + 1, k - 1) * k;
    if (j > 0) res += dfs(i + 1, j - 1, k) * j;
    if (i > 0) res += dfs(i - 1, j, k) * i;
    res += N;
    res /= (i + j + k);
    return dp[i][j][k] = res;
}
int main() {
    cin >> N;
    rep(i, N) {
        int a;
        cin >> a;
        if (a == 1)
            c1++;
        else if (a == 2)
            c2++;
        else
            c3++;
    }

    dp.resize(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, -1)));

    cout << fixed << setprecision(9) << dfs(c1, c2, c3) << endl;
    return 0;
}
