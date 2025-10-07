#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<int>> pos(26, vector<int>(N + 1, -1));
    for (int i = N - 1; i >= 0; --i) {
        rep(ch, 26) {
            if (ch == S[i] - 'a') {
                pos[ch][i] = i;
            } else {
                pos[ch][i] = pos[ch][i + 1];
            }
        }
    }

    string ans;
    int currI = 0;
    rep(i, K) {
        rep(currCh, 26) {
            if (pos[currCh][currI] == -1) {
                continue;
            } else if (pos[currCh][currI] > N - (K - ans.size())) {
                continue;
            } else {
                currI = pos[currCh][currI] + 1;
                ans += 'a' + currCh;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
