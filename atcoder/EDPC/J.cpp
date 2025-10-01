#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<vector<double>>> dp;
double rec(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    double res1 = rec(i - 1, j, k) * i;
    double res2 = rec(i + 1, j - 1, k) * j;
    double res3 = rec(i, j + 1, k - 1) * k;
    int N = dp.size() - 1;
    dp[i][j][k] = (res1 + res2 + res3 + N) / (i + j + k);
    return dp[i][j][k];
}

int main() {
    int N; cin >> N;
    int one, two, three;
    one = two = three = 0;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (a == 1) one += 1;
        else if(a == 2) two += 1;
        else three += 1;
    }

    dp.assign(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, -1)));
    dp[0][0][0] = 0;
    double res = rec(one, two, three);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
