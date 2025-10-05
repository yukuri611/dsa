#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];

    vector<int> sum(N + 1, 1);
    sum[0] = 0;

    int currI = 1;
    rep(i, Q) {
        int x = X[i];
        int y = Y[i];
        if (x < currI) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        for (int j = currI; j <= x; ++j) {
            ans += sum[j];
        }
        cout << ans << endl;
        currI = x + 1;
        sum[y] += ans;
    }

    return 0;
}
