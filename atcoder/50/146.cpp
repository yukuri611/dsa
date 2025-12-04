#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    ll Y, X;
};

S op(S a, S b) { return {max(b.Y, a.Y + b.X), a.X + b.X}; }

S e() { return {0, 0}; }

int main() {
    ll Q, K;
    cin >> Q >> K;
    vector<ll> Com(Q), D(Q), A(Q, -1);

    rep(i, Q) {
        cin >> Com[i];
        cin >> D[i];
        if (Com[i] == 1) cin >> A[i];
    }

    auto D_uni = D;
    D_uni.push_back(0);
    sort(D_uni.begin(), D_uni.end());
    D_uni.erase(unique(D_uni.begin(), D_uni.end()), D_uni.end());

    int ds = D_uni.size() - 1;
    vector<S> vec(ds);
    rep(i, ds) {
        ll len = D_uni[i + 1] - D_uni[i];
        vec[i] = {0, len * K};
    }
    segtree<S, op, e> seg(vec);
    vector<ll> res_list;
    rep(i, Q) {
        int com = Com[i];
        int idx = lower_bound(D_uni.begin(), D_uni.end(), D[i]) - D_uni.begin();
        int seg_idx = idx - 1;

        if (com == 1) {
            ll a = A[i];
            S cur = seg.get(seg_idx);
            cur.X -= a;
            // cur.Yは常に0(∵Yは葉ノード)
            seg.set(seg_idx, cur);
        } else {
            S node = seg.prod(0, seg_idx + 1);
            ll total_prod = (D[i] * K);
            ll Z = max(node.Y, node.X);
            res_list.push_back(total_prod - Z);
        }
    }

    for (auto res : res_list) cout << res << endl;
    return 0;
}
