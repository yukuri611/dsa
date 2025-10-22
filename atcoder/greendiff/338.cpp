#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int M = 5 * 1e5;
    vector<ll> vec(M * 4);
    LazySegmentTree st(vec);
    int offset = M;

    int res = 0;
    rep(i, N) {
        int l = A[i] - D + offset;
        int r = A[i] + D + offset;
        int maximum = st.query(l, r + 1);
        st.update(offset + A[i], offset + A[i] + 1, maximum + 1);
        res = max(res, maximum + 1);
    }

    cout << res << endl;
    return 0;
}
