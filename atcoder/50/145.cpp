#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    ll head_cnt;
    ll length;
};
using F = bool;

S op(S a, S b) { return {a.head_cnt + b.head_cnt, a.length + b.length}; }

S e() { return {0, 0}; }

S mapping(F f, S x) {
    if (f)
        return {x.length - x.head_cnt, x.length};
    else
        return x;
}

F composition(F f, F g) { return f ^ g; }

F id() { return false; }

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<ll> A(K), B(K), C(K), D(K);
    rep(i, K) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        B[i]++;
        D[i]++;
    }

    // 座圧
    vector<ll> X, Y;
    X.push_back(1);
    X.push_back(M + 1);
    Y.push_back(1);
    Y.push_back(N + 1);
    rep(i, K) {
        X.push_back(A[i]);
        X.push_back(B[i]);
        Y.push_back(C[i]);
        Y.push_back(D[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    vector<vector<pair<ll, ll>>> Event(X.size() + 1);
    rep(i, K) {
        int a = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
        int b = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
        int c = lower_bound(Y.begin(), Y.end(), C[i]) - Y.begin();
        int d = lower_bound(Y.begin(), Y.end(), D[i]) - Y.begin();
        Event[a].push_back({c, d});
        Event[b].push_back({c, d});
    }

    vector<S> vec(Y.size() - 1);
    rep(i, Y.size() - 1) { vec[i] = {Y[i + 1] - Y[i], Y[i + 1] - Y[i]}; }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec);
    ll res = 0;
    rep(i, X.size() - 1) {
        for (auto [c, d] : Event[i]) {
            seg.apply(c, d, true);
        }
        ll dx = X[i + 1] - X[i];
        ll dy = seg.prod(0, Y.size() - 1).head_cnt;
        res += dx * dy;
    }

    cout << res << endl;
    return 0;
}
