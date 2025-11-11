#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {-1, 1, 0, 0};  // up, down, right, left
vector<int> dc = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    rep(t, T) {
        int H, W;
        cin >> H >> W;
        vector<string> S(H);
        rep(i, H) cin >> S[i];

        priority_queue<tuple<int, int, int, int>> pq;

        while (!pq.empty()) {
            auto [cnt, r, c, dir] = pq.top();
            pq.pop();

            rep(i, 4) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!isInside(nr, nc, H, W)) continue;

                int nxt_cnt;
                if (i == dir) {
                    nxt_cnt = cnt;
                } else {
                    if (i == 0 && dir) }
                int nxt_cnt = cnt;
            }
        }
    }
}
