#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> c(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        if (c[i] != 0) continue;
        for (int j = i; j <= N; j += i) {
            c[j] += 1;
        }
    }

    int ans = 0;
    rep(i, N + 1) {
        if (c[i] >= K) ans++;
    }
    cout << ans << endl;
    return 0;
}
