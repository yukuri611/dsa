#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
}
