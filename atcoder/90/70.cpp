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
    ll Xcenter = X[N / 2];
    ll Ycenter = Y[N / 2];
    ll distX = 0;
    ll distY = 0;
    rep(i, N) {
        distX += abs(X[i] - Xcenter);
        distY += abs(Y[i] - Ycenter);
    }

    cout << distX + distY << endl;
    return 0;
}
