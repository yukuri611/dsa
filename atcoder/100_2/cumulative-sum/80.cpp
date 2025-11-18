#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int H, W;
    ll K, V;
    cin >> H >> W >> K >> V;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H) { rep(j, W) cin >> A[i][j]; }

    vector<vector<ll>> sum_A(H + 1, vector<ll>(W + 1, 0));
    rep(i, H) rep(j, W) {
        sum_A[i + 1][j + 1] =
            sum_A[i][j + 1] + sum_A[i + 1][j] - sum_A[i][j] + A[i][j];
    }

    // 尺取り法
    int res = 0;
    rep(j, H + 1) {
        rep(i, j) {
            int r = 0;
            ll const_cost = (j - i) * K;

            ll sum = 0;
            rep(l, W) {
                ll nxt_cost = sum_A[j][r + 1] - sum_A[i][r + 1] - sum_A[j][r] +
                              sum_A[i][r];
                while (r < W && sum + nxt_cost + const_cost <= V) {
                    sum += (nxt_cost + const_cost);
                    r++;
                    nxt_cost = sum_A[j][r + 1] - sum_A[i][r + 1] - sum_A[j][r] +
                               sum_A[i][r];
                }
                int curr_area = (j - i) * (r - l);
                res = max(res, curr_area);
                if (r == l)
                    r++;
                else {
                    sum -= sum_A[j][l + 1] - sum_A[i][l + 1] - sum_A[j][l] +
                           sum_A[i][l];
                    sum -= const_cost;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
