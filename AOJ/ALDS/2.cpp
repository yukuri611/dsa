#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;
    int res = GCD(x, y);
    cout << res << endl;
    return 0;
}
