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
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    vector<vector<bool>> canPass(H, vector<bool>(W, true));
    map<char, int> Map = {{'v', 0}, {'^', 2}, {'<', 3}, {'>', 1}};
    rep(i, H) {
        rep(j, W) {
            char a = A[i][j];
            if (a == '#')
                canPass[i][j] = false;
            else if (a == '>' || a == '<' || a == '^' || a == 'v') {
                int r = i, c = j;
                canPass[r][c] = false;
                while (true) {
                    int nr = r + dr[Map[a]], nc = c + dc[Map[a]];
                    if (nr < 0 || nr >= H || nc < 0 || nc >= W) break;
                    char a = A[nr][nc];
                    if (a == '#' || a == '>' || a == '<' || a == '^' ||
                        a == 'v')
                        break;
                    canPass[nr][nc] = false;
                    r = nr;
                    c = nc;
                }
            }
        }
    }

    int sr, sc, gr, gc;
    rep(i, H) {
        rep(j, W) {
            if (A[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if (A[i][j] == 'G') {
                gr = i;
                gc = j;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
    dist[sr][sc] = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        rep(i, 4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (!canPass[nr][nc]) continue;
            if (dist[nr][nc] != INT_MAX) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    if (dist[gr][gc] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[gr][gc] << endl;
    return 0;
}
