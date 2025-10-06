#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll INF = 1e18;

class SegmentTree {
    int n; 
    vector<ll> node;

    void updatePrivate(int k, ll x) {
        k += n-1;
        node[k] = x;
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll queryPrivate(int a, int b, int k, int l, int r) {
        if (a >= r || b <= l) return -INF;
        if (a <= l && r <= b) return node[k];
        ll vl = queryPrivate(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = queryPrivate(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }

    public:
    SegmentTree(vector<ll> &v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        rep(i, sz) node[n - 1 + i] = v[i];
        for (int i = n - 2; i >= 0; --i) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int k, ll x) {
        updatePrivate(k, x);
    }
    
    ll query(int a, int b) {
        return queryPrivate(a, b, 0, 0, n);
    }

};

int main() {
    int W, N; cin >> W >> N;
    vector<int> L(N), R(N);
    vector<ll> V(N);
    rep(i, N) cin >> L[i] >> R[i] >> V[i];

    vector<ll> dp(W + 1, -1);
    dp[0] = 0;
    SegmentTree st(dp);

    rep(i, N) {
        auto nextDp = dp;
        int l = L[i];
        int r = R[i];
        ll v = V[i];
        for(int j = l; j <= W; ++j) {
            ll currMax = -1;
            if (j - r < 0) currMax = st.query(0, j - l + 1);
            else currMax = st.query(j - r, j - l + 1);
            if (currMax == -1) continue;
            else if (dp[j] < currMax + v) {
                nextDp[j] = currMax + v;
            }
        }
        rep(j, W) {
            st.update(j, nextDp[j]);
        }
        dp = nextDp;
    }

    cout << dp[W] << endl;
    return 0;
}
