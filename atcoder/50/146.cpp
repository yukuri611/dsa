#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    ll X, Y;
};
S op(S a, S b) { return {a.X + b.X, max(a.Y + b.X, b.Y)}; }
S e() { return {0, (ll)-4e18}; }

int main() {
    ll Q, K;
    cin >> Q >> K;
    vector<ll> Com(Q), D(Q), A(Q);
    rep(i, Q) {
        cin >> Com[i];
        if (Com[i] == 1)
            cin >> D[i] >> A[i];
        else
            cin >> D[i];
    }

    auto D_id = D;
    D_id.push_back(0);
    sort(D_id.begin(), D_id.end());
    D_id.erase(unique(D_id.begin(), D_id.end()), D_id.end());

    int sz = D_id.size();

    vector<S> vec(sz - 1);
    rep(i, sz - 1) { vec[i] = {(D_id[i + 1] - D_id[i]) * K, 0}; }
    segtree<S, op, e> seg(vec);
    vector<ll> res_list;
    rep(i, Q) {
        int d = lower_bound(D_id.begin(), D_id.end(), D[i]) - D_id.begin();
        int seg_idx = d - 1;
        if (Com[i] == 1) {
            ll a = A[i];
            auto [cur_x, cur_y] = seg.get(seg_idx);
            seg.set(seg_idx, {cur_x - a, cur_y});
        } else {
            auto [x, y] = seg.prod(0, seg_idx + 1);
            res_list.push_back(D[i] * K - max(y, x));
        }
    }

    for (auto res : res_list) cout << res << endl;
    return 0;
}
