#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    // input
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    // syakutori
    int r = 0;
    int c = 0;
    int res = 0;
    map<int, int> cnt;
    rep(l, N) {
        while (r < N) {
            if (cnt[A[r]] == 0 && c == K) break;
            if (cnt[A[r]] == 0) c++;
            cnt[A[r]]++;
            r++;
        }
        res = max(res, r - l);
        if (cnt[A[l]] == 1) c--;
        cnt[A[l]]--;
    }

    // output
    cout << res << endl;
    return 0;
}
