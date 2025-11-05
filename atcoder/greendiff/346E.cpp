#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, M;
    cin >> H >> W >> M;
    vector<int> T(M), A(M), X(M);
    rep(i, M) {
        cin >> T[i] >> A[i] >> X[i];
        A[i]--;
    }

    vector<bool> decidedR(H, false), decidedC(W, false);
    ll cntR = H, cntC = W;
    vector<ll> colorCnt(2e5 + 1);
    for (int i = M - 1; i >= 0; --i) {
        int t = T[i], a = A[i], x = X[i];
        if (t == 1) {
            if (decidedR[a]) continue;
            decidedR[a] = true;
            colorCnt[x] += cntC;
            cntR--;
        } else {
            if (decidedC[a]) continue;
            decidedC[a] = true;
            colorCnt[x] += cntR;
            cntC--;
        }
    }
    colorCnt[0] += cntR * cntC;

    vector<pair<ll, ll>> res;
    rep(i, 2e5 + 1) {
        if (colorCnt[i] != 0) res.push_back({i, colorCnt[i]});
    }
    cout << res.size() << endl;
    for (auto [color, cnt] : res) cout << color << " " << cnt << endl;
    return 0;
}
