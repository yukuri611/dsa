#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll d_total, n, m;
    cin >> d_total >> n >> m;
    vector<ll> D(n + 1);
    D[0] = 0;
    D[n] = d_total;
    for (int i = 1; i < n; ++i) cin >> D[i];
    sort(D.begin(), D.end());
    vector<ll> K(m);
    rep(i, m) cin >> K[i];

    ll res = 0;
    rep(i, m) {
        ll k = K[i];
        ll index = lower_bound(D.begin(), D.end(), k) - D.begin();
        ll dist;
        if (index == 0)
            dist = k - D[index];
        else
            dist = min(D[index] - k, k - D[index - 1]);
        res += dist;
    }

    cout << res << endl;
    return 0;
}
