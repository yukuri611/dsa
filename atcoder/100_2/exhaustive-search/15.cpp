#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    double res = 0;
    int cnt = 0;
    do {
        double total_dist = 0;
        rep(i, N - 1) {
            int x1 = X[p[i]], y1 = Y[p[i]], x2 = X[p[i + 1]], y2 = Y[p[i + 1]];
            int dx = x1 - x2;
            int dy = y1 - y2;
            double dist = sqrt(dx * dx + dy * dy);
            total_dist += dist;
        }
        res += total_dist;
        cnt++;
    } while (next_permutation(p.begin(), p.end()));

    res /= cnt;
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
