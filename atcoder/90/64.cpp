#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> diff(N);  // diff[i] = E[i] - E[i - 1];
    ll prev;
    cin >> prev;
    for (int i = 1; i < N; ++i) {
        int a;
        cin >> a;
        diff[i] = a - prev;
        prev = a;
    }

    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += abs(diff[i]);
    }

    rep(_, Q) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        if (l > 0) {
            ans -= abs(diff[l]);
            diff[l] += v;
            ans += abs(diff[l]);
        }
        if (r + 1 < N) {
            ans -= abs(diff[r + 1]);
            diff[r + 1] -= v;
            ans += abs(diff[r + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
