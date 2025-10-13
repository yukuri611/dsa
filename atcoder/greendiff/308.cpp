#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int mex(int a, int b, int c) {
    int res = 0;
    if (a == 0 || b == 0 || c == 0) res = 1;
    if (res == 1 && (a == 1 || b == 1 || c == 1)) res = 2;
    if (res == 2 && (a == 2 || b == 2 || c == 2)) res = 3;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    string S;
    cin >> S;

    vector<vector<int>> M(N + 1, vector<int>(3, 0));
    vector<vector<int>> X(N + 1, vector<int>(3, 0));
    rep(i, N) {
        if (S[i] == 'M') {
            M[i][A[i]]++;
        } else if (S[i] == 'X') {
            X[i][A[i]]++;
        }
    }

    rep(i, N) {
        rep(j, 3) {
            M[i + 1][j] += M[i][j];
            X[i + 1][j] += X[i][j];
        }
    }

    ll res = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (S[i] == 'E') {
            rep(j, 3) {
                rep(k, 3) {
                    int val = mex(A[i], j, k);
                    ll total_val =
                        (ll)M[i - 1][j] * (X[N - 1][k] - X[i][k]) * val;
                    res += total_val;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
