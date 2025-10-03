#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

struct state {
    int r, c, dir;
};

int main() {
    int H, W;
    cin >> H >> W;
    int rs, cs;
    cin >> rs >> cs;
    rs--;
    cs--;
    int rt, ct;
    cin >> rt >> ct;
    rt--;
    ct--;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    // 0-1 BFS
    vector<vector<vector<int>>> dist(
        H, vector<vector<int>>(W, vector<int>(4, INT_MAX)));
    deque<state> deq;
    rep(i, 4) {
        dist[rs][cs][i] = 0;
        deq.push_back({rs, cs, i});
    }

    while (!deq.empty()) {
        auto [r, c, d] = deq.front();
        deq.pop_front();
        rep(i, 4) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int new_cost = dist[r][c][d] + ((d != i) ? 1 : 0);
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (S[nr][nc] == '#') continue;
            if (dist[nr][nc][i] > new_cost) {
                dist[nr][nc][i] = new_cost;
                if (i == d)
                    deq.push_front({nr, nc, i});
                else
                    deq.push_back({nr, nc, i});
            }
        }
    }
    int res = INT_MAX;
    rep(i, 4) { res = min(res, dist[rt][ct][i]); }

    cout << res << endl;
    return 0;
}
