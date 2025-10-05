#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < (N); ++i)

class LazySegmentTree {
   private:
    int n;
    vector<int> node, lazy;

    void eval(int k, int l, int r) {
        if (lazy[k] == -1) return;
        node[k] = lazy[k];
        if (r - l > 1) {
            // if not leaf, transmit
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }

        lazy[k] = -1;
    }

    void update(int a, int b, int x, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) {
            return node[k];
        } else {
            int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

   public:
    LazySegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.assign(2 * n - 1, 0);
        lazy.assign(2 * n - 1, -1);
    }

    void update(int a, int b, int x) { update(a, b, x, 0, 0, n); }
    int query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
    int W, N;
    cin >> W >> N;
    LazySegmentTree st(W + 1);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        int maxHeight = st.query(l, r + 1);
        int newHeight = maxHeight + 1;
        st.update(l, r + 1, newHeight);
        cout << newHeight << endl;
    }
    return 0;
}
