#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <typename T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n) {
        rep(j, m) {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] == dp[i][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
