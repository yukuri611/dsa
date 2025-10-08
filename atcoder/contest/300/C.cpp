#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    //input
    int H, W; cin >> H >> W;
    int N = min(H, W);
    vector<string> C(H);
    rep(i, H) {
        cin >> C[i];  
    }

    auto ok = [&](int i, int j) {return i > -1 && i < H && j > -1 && j < W;};
    vector<int> cnt(N + 1, 0);
    rep(i, H) {
        rep(j, W) {
            if(C[i][j] == '.') continue;
            int l = 0;
            while(true) {
                bool valid = true;
                for (auto &x: vector<int>{l, -l}) {
                    for (auto &y: vector<int>{l, -l}) {
                        int ni = i + x; int nj = j + y;
                        if (!ok(ni, nj) || C[ni][nj] != '#') valid = false;
                    }
                }
                if (!valid) break;
                l++;
            }
            cnt[l-1]++;
        }   
    }

    for (int i = 1; i <= N; ++i) cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
