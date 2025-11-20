#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(M);
    rep(i, M) cin >> P[i];
    rep(i, M) P[i]--;
    vector<ll> A(N - 1), B(N - 1), C(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i] >> C[i];

    vector<int> S(N - 1, 0);
    rep(i, M - 1) {
        int cur = P[i], nxt = P[i + 1];
        if (cur > nxt) swap(cur, nxt);
        S[cur]++;
        S[nxt]--;
    }

    rep(i, N - 2) { S[i + 1] += S[i]; }

    ll res = 0;
    rep(i, N - 1) { res += min(A[i] * S[i], B[i] * S[i] + C[i]); }

    cout << res << endl;
    return 0;
}
