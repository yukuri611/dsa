#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int M, N;
    cin >> M >> N;
    int K;
    cin >> K;
    vector<string> S(M);
    rep(i, M) cin >> S[i];

    vector<vector<int>> sum_j(M + 1, vector<int>(N + 1, 0)),
        sum_o(M + 1, vector<int>(N + 1, 0)),
        sum_i(M + 1, vector<int>(N + 1, 0));
    rep(i, M) {
        rep(j, N) {
            sum_j[i + 1][j + 1] =
                sum_j[i + 1][j] + sum_j[i][j + 1] - sum_j[i][j];
            sum_o[i + 1][j + 1] =
                sum_o[i + 1][j] + sum_o[i][j + 1] - sum_o[i][j];
            sum_i[i + 1][j + 1] =
                sum_i[i + 1][j] + sum_i[i][j + 1] - sum_i[i][j];
            if (S[i][j] == 'J')
                sum_j[i + 1][j + 1] += 1;
            else if (S[i][j] == 'O')
                sum_o[i + 1][j + 1] += 1;
            else
                sum_i[i + 1][j + 1] += 1;
        }
    }

    rep(i, K) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int cnt_j = sum_j[c + 1][d + 1] - sum_j[c + 1][b] - sum_j[a][d + 1] +
                    sum_j[a][b];
        int cnt_o = sum_o[c + 1][d + 1] - sum_o[c + 1][b] - sum_o[a][d + 1] +
                    sum_o[a][b];
        int cnt_i = sum_i[c + 1][d + 1] - sum_i[c + 1][b] - sum_i[a][d + 1] +
                    sum_i[a][b];
        cout << cnt_j << " " << cnt_o << " " << cnt_i << endl;
    }
    return 0;
}
