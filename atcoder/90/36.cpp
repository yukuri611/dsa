#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    vector<ll> Y(N);
    ll min_X = INT_MAX;
    ll max_X = INT_MIN;
    ll min_Y = INT_MAX;
    ll max_Y = INT_MIN;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        X[i] = x - y;
        Y[i] = x + y;
    }
    for (int i = 0; i < N; ++i) {
        min_X = min(min_X, X[i]);
        max_X = max(max_X, X[i]);
        min_Y = min(min_Y, Y[i]);
        max_Y = max(max_Y, Y[i]);
    }

    rep(i, Q) {
        int q;
        cin >> q;
        q--;
        ll x = X[q];
        ll y = Y[q];
        ll d1 = abs(x - min_X);
        ll d2 = abs(x - max_X);
        ll d3 = abs(y - min_Y);
        ll d4 = abs(y - max_Y);
        cout << max({d1, d2, d3, d4}) << endl;
    }
    return 0;
}
