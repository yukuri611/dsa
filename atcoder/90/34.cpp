#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, int> Map;
    int r = 0;
    int c = 0;
    int res = 0;
    rep(l, N) {
        while (r < N) {
            if (c == K && Map[A[r]] == 0) break;
            if (Map[A[r]] == 0) c++;
            Map[A[r]] += 1;
            r++;
        }
        res = max(res, r - l);
        if (Map[A[l]] == 1) c--;
        Map[A[l]] -= 1;
    }
    cout << res << endl;
    return 0;
}
