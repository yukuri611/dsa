#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll INF = 1e18;

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> X(N), Y(N);
    ll minX, minY, maxX, maxY;
    minX = minY = INF;
    maxX = maxY = -INF;
    rep(i, N) {
        int x, y; cin >> x >> y;
        X[i] = x - y;
        Y[i] = x + y;
        minX = min(minX, X[i]);
        minY = min(minY, Y[i]);
        maxX = max(maxX, X[i]);
        maxY = max(maxY, Y[i]);
    }

    rep(i, Q) {
        int q; cin >> q;
        q--;
        ll dist1 = abs(X[q] - minX);
        ll dist2 = abs(maxX - X[q]);
        ll dist3 = abs(Y[q] - minY);
        ll dist4 = abs(maxY - Y[q]);
        ll res = max({dist1, dist2, dist3, dist4});
        cout << res << endl;
    }

    return 0;
}
