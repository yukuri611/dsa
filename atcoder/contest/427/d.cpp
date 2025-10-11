#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    vector<char> res_list;
    rep(i, T) {
        // input
        int N, M, K;
        cin >> N >> M >> K;
        string S;
        cin >> S;
        vector<vector<int>> G(N);
        rep(i, M) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push_back(v);
        }

        vector<vector<char>> dp(N, vector<char>(2 * K + 1));
        rep(i, N) dp[i][0] = S[i];
        for (int i = 1; i < 2 * K + 1; ++i) {
            rep(j, N) {
                if (i % 2) {
                    // bの番
                    bool canWin = false;
                    for (int child : G[j]) {
                        if (dp[child][i - 1] == 'B') {
                            canWin = true;
                            break;
                        }
                    }
                    if (canWin)
                        dp[j][i] = 'B';
                    else
                        dp[j][i] = 'A';
                } else {
                    // aの番
                    bool canWin = false;
                    for (int child : G[j]) {
                        if (dp[child][i - 1] == 'A') {
                            canWin = true;
                            break;
                        }
                    }
                    if (canWin)
                        dp[j][i] = 'A';
                    else
                        dp[j][i] = 'B';
                }
            }
        }
        res_list.push_back(dp[0][2 * K]);
    }

    for (char c : res_list) {
        if (c == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}
