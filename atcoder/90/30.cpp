#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<int> cnt;

void countPrimeFactor(int N) {
    for (int i = 2; i < N; ++i) {
        if (cnt[i] != 0) continue;
        for (int j = 1; i * j <= N; ++j) {
            cnt[i * j]++;
        }
    }
}

int main() {
    int N, K; cin >> N >> K;
    cnt.resize(N + 1, 0);
    countPrimeFactor(N);

    int res = 0;
    for (int i = 2; i <= N; ++i) {
        if (cnt[i] >= K) res++;
    }
    cout << res << endl;
    return 0;
}
