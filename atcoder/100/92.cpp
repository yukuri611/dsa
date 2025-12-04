#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    vector<int> res_list;
    while (true) {
        int H;
        cin >> H;
        if (H == 0) break;
        int W = 5;
        vector<vector<int>> A(H, vector<int>(W));
        rep(i, H) rep(j, W) cin >> A[i][j];

        int cnt = 0;

        int ans = 0;

        while (true) {
            bool changed = false;

            rep(i, H) {
                rep(j, W) {
                    if (A[i][j] == -1) continue;
                    int len = 1;
                    while (j + len < W && A[i][j + len] == A[i][j]) {
                        len++;
                    }
                    if (len >= 3) {
                        // 消去
                        changed = true;
                        ans += A[i][j] * len;
                        rep(k, len) { A[i][j + k] = -1; }
                    }
                }
            }

            if (!changed) break;
            rep(j, W) {
                vector<int> newCol;
                rep(i, H) {
                    if (A[i][j] != -1) newCol.push_back(A[i][j]);
                }
                rep(i, H) {
                    if (i < H - newCol.size())
                        A[i][j] = -1;
                    else {
                        A[i][j] = newCol[i - (H - newCol.size())];
                    }
                }
            }
        }

        res_list.push_back(ans);
    }

    for (int res : res_list) cout << res << endl;
    return 0;
}
