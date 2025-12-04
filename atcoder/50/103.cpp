#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> X1(N), X2(N), Y1(N), Y2(N), D1(N), D2(N);
    rep(i, N) cin >> X1[i] >> Y1[i] >> D1[i] >> X2[i] >> Y2[i] >> D2[i];

    // 座圧
    vector<ll> X, Y, D;
    rep(i, N) {
        X.push_back(X1[i]);
        X.push_back(X2[i]);
        Y.push_back(Y1[i]);
        Y.push_back(Y2[i]);
        D.push_back(D1[i]);
        D.push_back(D2[i]);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(D.begin(), D.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    D.erase(unique(D.begin(), D.end()), D.end());

    int sx = X.size(), sy = Y.size(), sd = D.size();

    vector S(sx, vector(sy, vector(sd, 0LL)));
    rep(i, N) {
        int cx1 = lower_bound(X.begin(), X.end(), X1[i]) - X.begin();
        int cx2 = lower_bound(X.begin(), X.end(), X2[i]) - X.begin();
        int cy1 = lower_bound(Y.begin(), Y.end(), Y1[i]) - Y.begin();
        int cy2 = lower_bound(Y.begin(), Y.end(), Y2[i]) - Y.begin();
        int cd1 = lower_bound(D.begin(), D.end(), D1[i]) - D.begin();
        int cd2 = lower_bound(D.begin(), D.end(), D2[i]) - D.begin();

        S[cx1][cy1][cd1]++;
        S[cx1][cy2][cd1]--;
        S[cx2][cy1][cd1]--;
        S[cx2][cy2][cd1]++;
        S[cx1][cy1][cd2]--;
        S[cx1][cy2][cd2]++;
        S[cx2][cy1][cd2]++;
        S[cx2][cy2][cd2]--;
    }

    rep(j, sy) rep(k, sd) rep(i, sx - 1) S[i + 1][j][k] += S[i][j][k];
    rep(i, sx) rep(k, sd) rep(j, sy - 1) S[i][j + 1][k] += S[i][j][k];
    rep(i, sx) rep(j, sy) rep(k, sd - 1) S[i][j][k + 1] += S[i][j][k];

    ll res = 0;
    rep(i, sx - 1) {
        rep(j, sy - 1) {
            rep(k, sd - 1) {
                if (S[i][j][k] >= K) {
                    ll cur_volume = (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]) *
                                    (D[k + 1] - D[k]);
                    res += cur_volume;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
