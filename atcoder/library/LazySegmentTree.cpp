ll INF = 1e18;

class LazySegmentTree {
    int n;
    vector<int> node, lazy;

    void eval(int k, int l, int r) {
        if (lazy[k] == 0) return;
        node[k] = lazy[k];
        if (r - l > 1) {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        lazy[k] = 0;
    }

    void update(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (a >= r || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
            return;
        }

        update(a, b, x, 2 * k + 1, l, (l + r) / 2);
        update(a, b, x, 2 * k + 2, (l + r) / 2, r);
        node[k] = max(node[2 * k + 1], node[2 * k + 2]);
    }

    ll query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (a >= r || b <= l) return -INF;
        if (a <= l && r <= b) {
            return node[k];
        }
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }

   public:
    LazySegmentTree(vector<ll>& vec) {
        int sz = vec.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        lazy.resize(2 * n - 1, 0);
        rep(i, sz) node[n - 1 + i] = vec[i];
        for (int i = n - 2; i > -1; --i)
            node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int a, int b, int x) { update(a, b, x, 0, 0, n); }

    ll query(int a, int b) { return query(a, b, 0, 0, n); }
};
