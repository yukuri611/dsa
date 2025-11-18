#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    int value;
    int size;
};
using F = int;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }

S e() { return {0, 0}; }

S mapping(F f, S x) {
    if (f) {
        x.value = x.size - x.value;
    }
    return x;
}

F composition(F f, F g) { return (f + g) % 2; }

F id() { return 0; }

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<S> A(n, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    rep(i, Q) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            seg.apply(l, r, 1);
        } else {
            S ans = seg.prod(l, r);
            cout << ans.value << endl;
        }
    }

    return 0;
}
