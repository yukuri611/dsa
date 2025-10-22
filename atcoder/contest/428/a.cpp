#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int S, A, B, X;
    cin >> S >> A >> B >> X;

    int res = 0;
    int t = 0;
    while (t <= X - A) {
        res += S * A;
        t += A + B;
    }
    if (t < X) {
        res += (X - t) * S;
    }
    cout << res << endl;
    return 0;
}
