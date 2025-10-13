#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> X(N), Y(N);
    rep(i, Q) { cin >> X[i] >> Y[i]; }

    multiset<ll> x, y;
    rep(i, K) x.insert(0);
    rep(i, N - K) x.insert(0);
    ll f = 0;

    rep(i, Q) { int x = X[i], y = Y[i]; }
}
