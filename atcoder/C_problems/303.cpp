#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

map<char, int> dx = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int, int>> Set;
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        Set.insert({x, y});
    }

    int x = 0, y = 0;
    int currH = H;
    rep(i, N) {
        currH--;
        if (currH < 0) {
            cout << "No" << endl;
            return 0;
        }
        int nx = x + dx[S[i]], ny = y + dy[S[i]];
        if (Set.count({nx, ny}) && currH < K) {
            currH = K;
            Set.erase({nx, ny});
        }
        x = nx;
        y = ny;
    }

    cout << "Yes" << endl;
    return 0;
}
