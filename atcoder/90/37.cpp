#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

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
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
    int W, N;
    cin >> W >> N;
    vector<int> L(N), R(N), V(N);
    rep(i, N) cin >> L[i] >> R[i] >> V[i];

    vector<ll> dp(W + 1, -INF);
    dp[0] = 0;
    SegmentTree st(dp);

    rep(i, N) {
        int l = L[i], r = R[i];
        ll v = V[i];
        vector<ll> nextDp = dp;
        for (int j = l; j < W + 1; ++j) {
            ll maxValue = st.query(max(j - r, 0), j - l + 1);
            if (maxValue == -INF) continue;
            nextDp[j] = max(nextDp[j], maxValue + v);
        }
        SegmentTree nextSt(nextDp);
        dp = nextDp;
        st = nextSt;
    }

    ll res = dp[W];
    if (res == -INF)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}
