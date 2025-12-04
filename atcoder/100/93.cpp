#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    int ans = 0;
    rep(erase_h, H) {
        rep(erase_w, W) {
            auto originalA = A;
            A[erase_h][erase_w] = '0';
            vector<char> newCol;
            rep(i, H) {
                if (A[H - 1 - i][erase_w] != '0')
                    newCol.push_back(A[H - 1 - i][erase_w]);
            }
            while (newCol.size() <= H) newCol.push_back('0');
            rep(i, H) A[i][erase_w] = newCol[H - 1 - i];

            // ループ処理
            int score = 0;
            int cnt = 0;
            while (true) {
                bool changed = false;
                int sum = 0;
                rep(i, H) {
                    rep(j, W) {
                        if (A[i][j] == '0') continue;
                        int len = 1;
                        while (j + len < W && A[i][j] == A[i][j + len]) {
                            len++;
                        }
                        if (len >= K) {
                            // 消去
                            changed = true;
                            sum += len * (A[i][j] - '0');
                            rep(k, len) A[i][j + k] = '0';
                        }
                    }
                }
                if (!changed) break;
                score += pow(2, cnt) * sum;
                // 石を下に詰める
                rep(j, W) {
                    vector<char> newCol;
                    rep(i, H) {
                        if (A[H - 1 - i][j] != '0')
                            newCol.push_back(A[H - 1 - i][j]);
                    }
                    while (newCol.size() <= H) newCol.push_back('0');
                    rep(i, H) A[i][j] = newCol[H - 1 - i];
                }

                cnt++;
            }
            ans = max(ans, score);
            A = originalA;
        }
    }

    cout << ans << endl;
    return 0;
}
