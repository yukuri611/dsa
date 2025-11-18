#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> P(M);
    rep(i, M) {
        cin >> P[i];
        P[i]--;
    }
    vector<ll> A(N - 1), B(N - 1), C(N - 1);
    rep(i, N - 1) { cin >> A[i] >> B[i] >> C[i]; }

    vector<ll> S(N);
    rep(i, M - 1) {
        int u = P[i];
        int v = P[i + 1];
        if (v < u) swap(u, v);
        S[u]++;
        S[v]--;
    }

    rep(i, N - 1) S[i + 1] += S[i];

    ll res = 0;
    rep(i, N - 1) { res += min(A[i] * S[i], B[i] * S[i] + C[i]); }

    cout << res << endl;
    return 0;
}
