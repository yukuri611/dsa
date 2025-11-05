#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, x;
        cin >> n >> x;

        if (n == 0 && x == 0) return 0;

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int k = x - i - j;
                if (k > j && k <= n) ++res;
            }
        }

        cout << res << endl;
    }
}
