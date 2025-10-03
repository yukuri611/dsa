#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> P[i][j];
    int ans = 0;
    
    for (int s = 1; s < (1 << H); ++s) {
        map<int, int> Map;
        int curr_max = 0;
        rep(j, W) {
            int curr_num = -1;
            bool valid = true;
            rep(i, H) {
                if ((s >> i) & 1) {
                    if (curr_num == -1) curr_num = P[i][j];
                    else if (P[i][j] != curr_num) valid = false;
                }
            }
            if (valid) {
                //can use col j
                Map[curr_num]++;
                if (Map[curr_num] > curr_max) curr_max = Map[curr_num];
            }
        }
        int curr_total = curr_max * __builtin_popcount(s);
        ans = max(ans, curr_total);
    }

    cout << ans << endl;
    return 0;
}
