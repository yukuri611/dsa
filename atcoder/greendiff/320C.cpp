#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;
    int n = 3;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    int res = INT_MAX;
    rep(i, 10) {
        bool ok = true;
        for (const auto &s : S) {
            if (s.find(i + '0') == string::npos) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        do {
            int t = 0;
            rep(j, n) {
                int curr = p[j];
                while (S[curr][t % M] - '0' != i) {
                    t++;
                }
                t++;
            }
            t--;
            res = min(res, t);
        } while (next_permutation(p.begin(), p.end()));
    }

    if (res == INT_MAX) res = -1;
    cout << res << endl;
    return 0;
}
