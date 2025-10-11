#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string T;
    cin >> T;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> A(N);
    rep(i, N) {
        int M = S[i].size();
        int cnt = 0;
        rep(j, M) {
            if (S[i][j] == T[cnt]) {
                cnt++;
                if (cnt == T.size()) break;
            }
        }
        A[i] = cnt;
    }

    vector<int> B(N);
    rep(i, N) {
        int M = S[i].size();
        int cnt = 0;
        for (int j = M - 1; j > -1; --j) {
            if (S[i][j] == T[T.size() - 1 - cnt]) {
                cnt++;
                if (cnt == T.size()) break;
            }
        }
        B[i] = cnt;
    }

    sort(B.begin(), B.end());

    ll res = 0;
    rep(i, N) {
        int a = A[i];
        res += B.end() - lower_bound(B.begin(), B.end(), T.size() - a);
    }

    cout << res << endl;
    return 0;
}
