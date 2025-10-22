#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    rep(i, n) cin >> R[i];

    int currmin = R[0];
    int res = INT_MIN;
    for (int i = 1; i < n; ++i) {
        res = max(res, R[i] - currmin);
        currmin = min(currmin, R[i]);
    }

    cout << res << endl;
    return 0;
}
