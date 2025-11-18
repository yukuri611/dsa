#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), X(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> X[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<ll>> S(N + 2, vector<ll>(N + 2, 0));
    rep(i, M) {
        int a = A[i], b = B[i], x = X[i];
        S[a][b]++;
        S[a][b + 1]--;
        S[a + x + 1][b]--;
        S[a + x + 2][b + 1]++;
        S[a + x + 1][b + x + 2]++;
        S[a + x + 2][b + x + 2]--;
    }

    rep(i, N + 2) { rep(j, N + 1) S[i][j + 1] += S[i][j]; }
    rep(j, N + 2) { rep(i, N + 1) S[i + 1][j] += S[i][j]; }
    rep(i, N + 1) { rep(j, N + 1) S[i + 1][j + 1] += S[i][j]; }

    ll res = 0;
    rep(i, N + 2) rep(j, N + 2) if (S[i][j]) res++;

    cout << res << endl;
    return 0;
}
