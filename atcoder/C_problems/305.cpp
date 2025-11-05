#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<int> cntR(H, 0), cntC(W, 0);
    rep(i, H) {
        string s = S[i];
        cntR[i] = count(s.begin(), s.end(), '#');
    }

    rep(i, W) {
        rep(j, H) {
            if (S[j][i] == '#') cntC[i]++;
        }
    }

    int r = 0;
    int cnt = INT_MAX;
    rep(i, H) {
        if (cntR[i] == 0) continue;
        if (cntR[i] < cnt) {
            r = i;
            cnt = cntR[i];
        }
    }
    int c = 0;
    cnt = INT_MAX;
    rep(i, W) {
        if (cntC[i] == 0) continue;
        if (cntC[i] < cnt) {
            c = i;
            cnt = cntC[i];
        }
    }

    cout << r + 1 << " " << c + 1 << endl;
    return 0;
}
