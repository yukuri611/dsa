#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> S(N, vector<int>(N));
    rep(i, M) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        S[l][r]++;
    }

    rep(i, N) {
        rep(j, N - 1) { S[i][j + 1] += S[i][j]; }
    }

    rep(i, N) {
        for (int j = N - 2; j >= 0; --j) {
            S[j][i] += S[j + 1][i];
        }
    }

    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        cout << S[p][q] << endl;
    }
    return 0;
}
