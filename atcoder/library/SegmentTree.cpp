ll INF = 1e18;

class SegmentTree {
    int n;
    vector<ll> node;

    ll query(int a, int b, int k, int l, int r) {
        if (a >= r || b <= l) return -INF;
        if (a <= l && r <= b) {
            return node[k];
        }
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }

   public:
    SegmentTree(vector<ll>& vec) {
        int sz = vec.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        rep(i, sz) node[n - 1 + i] = vec[i];
        for (int i = n - 2; i > -1; --i)
            node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int k, ll x) {
        k += n - 1;
        node[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n); }
};
