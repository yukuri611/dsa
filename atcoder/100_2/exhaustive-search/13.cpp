#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    rep(i, R) rep(j, C) cin >> A[i][j];

    int res = 0;
    rep(i, (1 << R)) {
        int total_count = 0;
        rep(j, C) {
            int cnt = 0;
            rep(k, R) {
                int a = A[k][j];
                if ((i >> k) & 1) a = 1 - a;
                cnt += a;
            }
            total_count += max(cnt, R - cnt);
        }
        res = max(total_count, res);
    }

    cout << res << endl;
    return 0;
}
