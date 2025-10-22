// 制約がでかいので、一回の移動をlog(N)いかに抑えなくてはならない。
// 移動する石の値は、k個の箱において同じ。残りN-k個の値においては、そのほかの箱+1
// segmenttreeを使うことで、logNで値を均等に増やすことが可能。
// segmenttreeとrotationが相性悪い。
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll INF = 1e18;

class LazySegmentTree {
    int n;
    vector<ll> node, lazy;

    void eval(int k, int l, int r) {
        if (lazy[k] == 0) return;
        node[k] += lazy[k];
        if (r - l > 1) {
            lazy[2 * k + 1] += lazy[k];
            lazy[2 * k + 2] += lazy[k];
        }
        lazy[k] = 0;
    }

    void update(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (a >= r || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
            return;
        }

        update(a, b, x, 2 * k + 1, l, (l + r) / 2);
        update(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }

    ll query(int a, int k, int l, int r) {
        eval(k, l, r);
        if (l == a && a + 1 == r) return node[k];
        if (a < (l + r) / 2)
            return query(a, 2 * k + 1, l, (l + r) / 2);
        else
            return query(a, 2 * k + 2, (l + r) / 2, r);
    }

   public:
    LazySegmentTree(vector<ll>& vec) {
        int sz = vec.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
        lazy.resize(2 * n - 1, 0);
        rep(i, sz) node[n - 1 + i] = vec[i];
    }

    void update(int a, int b, ll x) { update(a, b, x, 0, 0, n); }

    ll query(int a) { return query(a, 0, 0, n); }
};

int N, M;

void solve(int b, LazySegmentTree& st) {
    ll cnt = st.query(b);
    st.update(b, b + 1, -cnt);
    ll cnt1 = cnt / N;
    ll cnt2 = cnt % N;
    st.update(0, N, cnt1);
    if (cnt2 > 0) {
        if (b + cnt2 < N) {
            st.update(b + 1, b + 1 + cnt2, 1);
        } else {
            st.update(b + 1, N, 1);
            int rem = cnt2 - (N - 1 - b);
            st.update(0, rem, 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(M);
    rep(i, M) cin >> B[i];

    LazySegmentTree st(A);
    rep(i, M) {
        int b = B[i];
        solve(b, st);
    }

    rep(i, N) { cout << st.query(i) << " "; }
    cout << endl;
    return 0;
}
