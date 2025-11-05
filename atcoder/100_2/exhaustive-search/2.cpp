#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int countFactor(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (n / i != i) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) continue;
        if (countFactor(i) == 8) res++;
    }

    cout << res << endl;
    return 0;
}
