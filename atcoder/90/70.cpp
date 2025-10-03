#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N; cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int mid = N / 2;
    int xt = X[mid];
    int yt = Y[mid];

    ll res = 0;
    rep(i, N) {
        res += abs(X[i] - xt);
        res += abs(Y[i] - yt);
    }
    cout << res << endl;
    return 0;
}
