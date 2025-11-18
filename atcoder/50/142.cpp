
// ここまでAClibrary

using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

using S = int;
using F = int;
int INF = 2e9;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) {
    if (f != 0) x += f;
    return x;
}
S composition(F f, F g) {
    if (f == 0) {
        return g;
    } else {
        return f + g;
    }
}
S id() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;

    vector<S> A(n, 0);

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
    rep(i, q) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            S ans = seg.prod(s, t + 1);
            cout << ans << endl;
        }
    }

    return 0;
}
