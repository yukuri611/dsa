#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    // 計算
    if (log2(a) < log2(pow(c, b)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
