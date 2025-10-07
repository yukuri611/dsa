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
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cnt = 0, all = 0;
            for (int k = L[i]; k <= R[i]; ++k) {
                for (int l = L[j]; l <= R[j]; ++l) {
                    if (k > l) ++cnt;
                    ++all;
                }
            }
            res += double(cnt) / all;
        }
    }

    cout << fixed << setprecision(7) << res << endl;
    return 0;
}
