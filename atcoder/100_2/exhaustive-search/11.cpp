#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> K(M);
    vector<vector<int>> S(M);
    rep(i, M) {
        int k;
        cin >> k;
        K[i] = k;
        rep(j, k) {
            int s;
            cin >> s;
            s--;
            S[i].push_back(s);
        }
    }
    vector<int> P(M);
    rep(i, M) cin >> P[i];

    int res = 0;
    rep(i, (1 << N)) {
        bool valid = true;
        rep(j, M) {
            int k = K[j];
            int cnt = 0;
            rep(l, k) {
                int s = S[j][l];
                if ((i >> s) & 1) cnt++;
            }
            if (cnt % 2 != P[j]) {
                valid = false;
                break;
            }
        }
        if (valid) res++;
    }

    cout << res << endl;
    return 0;
}
