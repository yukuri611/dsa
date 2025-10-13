#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    // bfs
    queue<tuple<int, int, int>> q;
    int rT, cT;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'T') {
                rT = i;
                cT = j;
            }
        }
    }
    q.push({rT, cT, 0});

    int res = 0;
    while (!q.empty()) {
        int M = q.size();
        rep(i, M) {
            auto [r, c, d] = q.front();
            q.pop();
            rep(j, 4) {
                int nr = r + dr[j], nc = c + dc[j];
                if (nr < 0 || nr >= H || nc < 0 || nc > +W) {
                    int diffR = nr - rT;

                    rep(k, H) {
                        rep(l, W) {
                            if (S[k][l] == '#') {
                            }
                        }
                    }
                } else {
                    q.push({nr, nc});
                }
            }
        }
    }
}
