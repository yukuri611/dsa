#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];

    double res = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            int divisor = 0;
            for (int k = L[j]; k <= R[j]; ++k) {
                int cnt = max(R[i] - k, 0);
                cnt = min(cnt, R[i] - L[i] + 1);
                divisor += cnt;
            }
            int dividend = (R[i] - L[i] + 1) * (R[j] - L[j] + 1);
            res += (double)divisor / dividend;
        }
    }

    cout << fixed << setprecision(7) << res << endl;
    return 0;
}
