#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
#define int ll
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vector<vector<int>> B(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> B[i][j];

    int total_count = 0;
    rep(i, H - 1) {
        rep(j, W - 1) {
            int diff = B[i][j] - A[i][j];
            A[i][j] += diff;
            A[i + 1][j] += diff;
            A[i][j + 1] += diff;
            A[i + 1][j + 1] += diff;
            total_count += abs(diff);
        }
        if (A[i][W - 1] != B[i][W - 1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(j, W) {
        if (A[H - 1][j] != B[H - 1][j]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << total_count << endl;
    return 0;
}
