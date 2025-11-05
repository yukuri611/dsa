#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<pair<int, int>> Set;
    vector<int> X(n), Y(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        Set.insert({x, y});
    }

    int res = 0;

    rep(i, n) {
        for (int j = i + 1; j < n; ++j) {
            int dx = X[i] - X[j];
            int dy = Y[i] - Y[j];

            // first square
            int x1 = X[i] + dy;
            int y1 = Y[i] - dx;
            int x2 = X[j] + dy;
            int y2 = Y[j] - dx;
            if (Set.count({x1, y1}) && Set.count({x2, y2})) {
                int area = dx * dx + dy * dy;
                res = max(res, area);
            }

            // second square
            x1 = X[i] - dy;
            y1 = Y[i] + dx;
            x2 = X[j] - dy;
            y2 = Y[j] + dx;
            if (Set.count({x1, y1}) && Set.count({x2, y2})) {
                int area = dx * dx + dy * dy;
                res = max(res, area);
            }
        }
    }

    cout << res << endl;
    return 0;
}
