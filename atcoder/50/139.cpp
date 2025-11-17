#include <bits/stdc++.h>

#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int op(int a, int b) { return min(a, b); }

int e() { return INT_MAX; }

int main() {
    int n, q;
    cin >> n >> q;

    segtree<int, op, e> seg(n);
    rep(i, q) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            // update
            seg.set(x, y);
        } else {
            // find
            auto res = seg.prod(x, y + 1);
            cout << res << endl;
        }
    }

    return 0;
}
