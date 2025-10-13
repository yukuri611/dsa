#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll midX = X[N / 2];
    ll midY = Y[N / 2];

    ll res = 0;
    rep(i, N) res += abs(X[i] - midX) + abs(Y[i] - midY);

    cout << res << endl;
    return 0;
}
