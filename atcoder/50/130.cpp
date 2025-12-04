#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> di = {1, 0, -1, 0}, dj = {0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> Grid(r);
    rep(i, r) cin >> Grid[i];

    int s = r * c;
    int t = r * c + 1;
    mf_graph<int> G(t + 1);
    int total_dots = 0;
    rep(i, r) {
        rep(j, c) {
            if (Grid[i][j] == '*') continue;
            total_dots++;
            int u = i * c + j;
            if ((i + j) % 2 == 0) {
                G.add_edge(s, u, 1);
                rep(k, 4) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                    if (Grid[ni][nj] == '*') continue;
                    int v = ni * c + nj;
                    G.add_edge(u, v, 1);
                }
            } else {
                G.add_edge(u, t, 1);
            }
        }
    }

    int matching = G.flow(s, t);
    int ans = total_dots - matching;
    cout << ans << endl;
    return 0;
}
