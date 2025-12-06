#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    dsu uf(N);

    vector<ll> connect_cnt(M + 1);

    for (int i = M - 1; i >= 0; --i) {
        if (uf.same(A[i], B[i])) {
            connect_cnt[i] = connect_cnt[i + 1];
        } else {
            ll cntA = uf.size(A[i]), cntB = uf.size(B[i]);
            uf.merge(A[i], B[i]);
            connect_cnt[i] = connect_cnt[i + 1] + cntA * cntB;
        }
    }

    ll total_pairs = N * (N - 1) / 2;
    rep(i, M) cout << total_pairs - connect_cnt[i + 1] << endl;
    return 0;
}
