#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    ll total_length;
    ll head_cnt;
};
using F = bool;
S op(S a, S b) {
    return {a.total_length + b.total_length, a.head_cnt + b.head_cnt};
}

S e() { return {0, 0}; }

S mapping(F f, S x) {
    if (f) {
        return {x.total_length, x.total_length - x.head_cnt};
    } else
        return x;
}

F composition(F f, F g) { return f ^ g; }

F id() { return false; }

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> A(K), B(K), C(K), D(K);
    rep(i, K) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        B[i]++;
        D[i]++;
    }

    // 座圧
    vector<int> X, Y;
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

    int sx = X.size(), sy = Y.size();
    // y方向にイベントをソート
    vector<vector<pair<int, int>>> Events(sy);
    rep(i, K) {
        int a = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
        int b = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
        int c = lower_bound(Y.begin(), Y.end(), C[i]) - Y.begin();
        int d = lower_bound(Y.begin(), Y.end(), D[i]) - Y.begin();
        Events[c].push_back({a, b});
        Events[d].push_back({a, b});
    }
    // セグ木で解く
    vector<S> vec(sx - 1);
    rep(i, sx - 1) {
        ll x1 = lower_bound(X.begin(), X.end(), X[i]) - X.begin();
        ll x2 = lower_bound(X.begin(), X.end(), X[i + 1]) - X.begin();

        vec[i] = {x2 - x1, x2 - x1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec);
    ll ans = 0;
    rep(i, sy) {
        for (auto [a, b] : Events[i]) {
            seg.apply(a, b);
        }
        ans += seg.prod(0, sx).head_cnt;
    }

    cout << ans << endl;
    return 0;
}
