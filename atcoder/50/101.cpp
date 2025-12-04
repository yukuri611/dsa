#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<ll> X1(N), X2(N), Y1(N), Y2(N);
    rep(i, N) { cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i]; }

    // 座圧
    vector<ll> X, Y;
    rep(i, N) {
        X.push_back(X1[i]);
        X.push_back(X2[i]);
        Y.push_back(Y1[i]);
        Y.push_back(Y2[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    // imos
    int sz_x = X.size(), sz_y = Y.size();
    vector<vector<int>> S(sz_y, vector<int>(sz_x, 0));
    rep(i, N) {
        int x1 = lower_bound(X.begin(), X.end(), X1[i]) - X.begin();
        int x2 = lower_bound(X.begin(), X.end(), X2[i]) - X.begin();
        int y1 = lower_bound(Y.begin(), Y.end(), Y1[i]) - Y.begin();
        int y2 = lower_bound(Y.begin(), Y.end(), Y2[i]) - Y.begin();
        S[y1][x1]++;
        S[y1][x2]--;
        S[y2][x1]--;
        S[y2][x2]++;
    }
    rep(i, sz_x - 1) rep(j, sz_y) S[j][i + 1] += S[j][i];
    rep(i, sz_x) rep(j, sz_y - 1) S[j + 1][i] += S[j][i];

    ll ans = 0;
    rep(i, sz_y - 1) {
        rep(j, sz_x - 1) {
            if (S[i][j] > 0) {
                ll area = (X[j + 1] - X[j]) * (Y[i + 1] - Y[i]);
                ans += area;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
