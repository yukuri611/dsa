#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1};

bool isInside(int r, int c, vector<string>& C) {
    int H = C.size();
    int W = C[0].size();
    return (r >= 0 && r < H && c >= 0 && c < W);
}

bool test(int r, int c, int d, vector<string>& C) {
    rep(i, 4) {
        int nr = r + dr[i] * d;
        int nc = c + dc[i] * d;
        if (!isInside(nr, nc, C)) return false;
        if (C[nr][nc] != '#') return false;
    }
    return true;
}

int solve(int r, int c, vector<string>& C) {
    int currR = r, currC = c;
    int d = 0;
    while (test(r, c, d + 1, C)) d++;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H) cin >> C[i];

    vector<int> S(min(H, W) + 1, 0);
    rep(i, H) {
        rep(j, W) {
            if (C[i][j] == '.') continue;
            int cnt = solve(i, j, C);
            if (cnt >= 1) {
                S[cnt]++;
            }
        }
    }

    for (int i = 1; i < S.size(); ++i) {
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;
}
