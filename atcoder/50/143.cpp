#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    int cnt0, cnt1;
};
using F = bool;
S op(S a, S b) { return {a.cnt0 + b.cnt0, a.cnt1 + b.cnt1}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if (f) {
        return {x.cnt1, x.cnt0};
    } else {
        return x;
    }
}
F composition(F f, F g) { return f ^ g; }
F id() { return false; }
int main() {
    int n, Q;
    cin >> n >> Q;
    vector<S> A(n, {1, 0});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    rep(i, Q) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            seg.apply(l, r, 1);
        } else {
            S res = seg.prod(l, r);
            cout << res.cnt1 << endl;
        }
    }
    return 0;
}
