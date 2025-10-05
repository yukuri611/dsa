#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

class SegmentTree {
   private:
    int n;
    vector<ll> node;

    void updatePrivate(int x, ll k) {
        x += n - 1;
        node[x] = k;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    ll query(int a, int b, int k, int l, int r) {
        if (a >= r || b <= l) return -1;
        if (a <= l && r <= b)
            return node[k];
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

   public:
    SegmentTree(vector<ll> &A) {
        int sz = A.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, -1);
        rep(j, sz) node[j + n - 1] = A[j];
        for (int j = n - 2; j >= 0; --j)
            node[j] = max(node[j * 2 + 1], node[j * 2 + 2]);
    }

    void update(int x, ll k) { updatePrivate(x, k); }

    ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
    int W, N;
    cin >> W >> N;
    vector<ll> dp(W + 1, -1);  // dp[i][W] = i-1の香辛料で、重さWの時の最大価値

    dp[0] = 0;
    SegmentTree st(dp);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        ll v;
        cin >> v;
        vector<ll> nextDp = dp;
        for (int j = l; j <= W; ++j) {
            int query_l = max(0, j - r);
            int query_r = j - l + 1;

            if (query_l >= query_r) continue;

            ll temp = st.query(query_l, query_r);
            if (temp == -1) continue;
            nextDp[j] = max(nextDp[j], temp + v);
        }
        rep(j, W + 1) { st.update(j, nextDp[j]); }
        dp = nextDp;
    }

    cout << dp[W] << endl;
    return 0;
}
