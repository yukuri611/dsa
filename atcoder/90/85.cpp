#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll INF = 1e18;

class LazySegmentTree {
    int n;
    vector<ll> node, lazy;

    void eval(int k, int l, int r) {
        if (lazy[k] == 0) return;
        node[k] = lazy[k];
        if(r - l > 1) {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] =lazy[k];
        }
        lazy[k] = 0;
    }

    void update(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || a >= r) return;
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
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) {
            return node[k];
        }
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

    public:
    LazySegmentTree(vector<ll> &v ) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        lazy.resize(2 * n - 1, 0);
        rep(i, sz) node[n-1 + i] = v[i];
        for(int i = n - 2; i > -1; --i) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int a, int b, ll x) {
        update(a, b, x, 0, 0, n);
    }

    ll query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

int main() {
    int W, N; cin >> W >> N;

    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    auto copy = L;
    copy.insert(copy.end(), R.begin(), R.end());
    
    sort(copy.begin(), copy.end());
    copy.erase(unique(copy.begin(), copy.end()), copy.end());
   
    rep(i, N) {
        int l = lower_bound(copy.begin(), copy.end(), L[i]) - copy.begin();
        int r = lower_bound(copy.begin(), copy.end(), R[i]) - copy.begin();
        L[i] = l;
        R[i] = r;
    }

    vector<ll> H(2 * N, 0);
    LazySegmentTree st(H);
    
    rep(i, N) {
        int l = L[i];
        int r = R[i];
        ll newHeight = st.query(l, r+1) + 1;
        st.update(l, r + 1, newHeight);
        cout << newHeight << endl;
    }

    return 0;

}
