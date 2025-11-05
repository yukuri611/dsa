#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll res = LLONG_MAX;

    rep(i, max(X, Y) * 2 + 1) {
        ll count_a = max(0LL, X - i / 2);
        ll count_b = max(0LL, Y - i / 2);
        ll cost = A * count_a + B * count_b + C * i;
        res = min(res, cost);
    }

    cout << res << endl;
    return 0;
}
