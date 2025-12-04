#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

using S = int;
using F = int;
S op(S a, S b) { return a + b; }

S e() { return 0; }

S mapping(F f, S x) { return f + x; }

F composition(F f, F g) { return f + g; }

F id() { return 0; }

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n), B(n);
    rep(i, n) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<int> P(m), Q(m), R(m);
    rep(i, m) {
        cin >> P[i] >> Q[i] >> R[i];
        P[i]--;
        Q[i]--;
        R[i]--;
    }

    // 座圧
    vector<int> X;
    rep(i, n) {
        X.push_back(A[i]);
        X.push_back(B[i]);
    }
    rep(i, m) X.push_back(P[i]);
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    vector<vector<tuple<int, int, int>>> Event(n);  // i, P[i], sign
    rep(i, m) {
        int p = lower_bound(X.begin(), X.end(), P[i]) - X.begin();
        int q = Q[i], r = R[i];
        if (q > 0) Event[q - 1].push_back({i, p, -1});
        Event[r].push_back({i, p, 1});
    }

    vector<int> vec(X.size(), 0);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec);
    vector<int> res_list(m);
    rep(i, n) {
        int a = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
        int b = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
        seg.apply(a, b + 1, 1);
        for (auto [j, p, sign] : Event[i]) {
            res_list[j] += seg.get(p) * sign;
        }
    }

    for (int res : res_list) cout << res << endl;
    return 0;
}
