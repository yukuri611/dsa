#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

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

    vector<vector<vector<int>>> Dist(
        H, vector<vector<int>>(W, vector<int>(4, INT_MAX)));
    deque<tuple<int, int, int, int>> deq;
    rep(i, 4) {
        Dist[rs][cs][i] = 0;
        deq.push_back({rs, cs, i, 0});
    }

    while (!deq.empty()) {
        auto [r, c, dir, dist] = deq.front();
        deq.pop_front();
        if (dist > Dist[r][c][dir]) continue;
        rep(i, 4) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int newDist = Dist[r][c][dir];
            if (dir != i) newDist++;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (S[nr][nc] == '#') continue;
            if (Dist[nr][nc][i] > newDist) {
                Dist[nr][nc][i] = newDist;
                if (dir == i)
                    deq.push_front({nr, nc, i, newDist});
                else
                    deq.push_back({nr, nc, i, newDist});
            }
        }
    }

    int res = INT_MAX;
    rep(i, 4) { res = min(res, Dist[rt][ct][i]); }
    cout << res << endl;
    return 0;
}
