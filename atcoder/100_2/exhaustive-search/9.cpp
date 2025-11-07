#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    vector<int> constellation_x(m), constellation_y(m);
    rep(i, m) { cin >> constellation_x[i] >> constellation_y[i]; }
    int n;
    cin >> n;
    vector<int> star_x(n), star_y(n);
    set<pair<int, int>> Set;
    rep(i, n) {
        cin >> star_x[i] >> star_y[i];
        Set.insert({star_x[i], star_y[i]});
    }

    rep(i, n) {
        int dx = star_x[i] - constellation_x[0],
            dy = star_y[i] - constellation_y[0];
        bool valid = true;
        for (int j = 1; j < m; ++j) {
            int curr_x = constellation_x[j] + dx,
                curr_y = constellation_y[j] + dy;
            if (Set.count({curr_x, curr_y}) == 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << dx << " " << dy << endl;
            return 0;
        }
    }
}
