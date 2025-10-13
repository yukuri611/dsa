#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const vector<vector<int>> lines = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // 横
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // 縦
    {0, 4, 8}, {2, 4, 6}              // 斜め
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 3;
    vector<int> C(9);
    rep(i, N) rep(j, N) cin >> C[i * 3 + j];

    vector<int> p(9);
    iota(p.begin(), p.end(), 0);
    ll numerator = 0;
    ll denominator = 0;
    do {
        denominator++;
        bool gakkari = false;
        for (auto& line : lines) {
            int pos0, pos1, pos2;
            rep(i, 9) {
                if (p[i] == line[0]) pos0 = i;
                if (p[i] == line[1]) pos1 = i;
                if (p[i] == line[2]) pos2 = i;
            }

            int last_pos = max({pos0, pos1, pos2});

            int c1, c2;
            if (last_pos == pos0) {
                c1 = C[p[pos1]];
                c2 = C[p[pos2]];
            }
            if (last_pos == pos1) {
                c1 = C[p[pos2]];
                c2 = C[p[pos0]];
            }
            if (last_pos == pos2) {
                c1 = C[p[pos0]];
                c2 = C[p[pos1]];
            }

            if (c1 == c2) gakkari = true;
        }
        if (!gakkari) numerator++;
    } while (next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(8) << (double)numerator / denominator << endl;
    return 0;
}
