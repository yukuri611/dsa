#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
#define int ll
    int N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;

    // 全探索
    int ans = 10000;
    for (int a = 0; a < 10000; ++a) {
        for (int b = 0; a + b < 10000; ++b) {
            ll remain = N - a * A - b * B;
            if (remain >= 0 && remain % C == 0) {
                int c = remain / C;
                ans = min(ans, a + b + c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
