#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, B;
    cin >> H >> B;
    int res = max(H - B, 0);
    cout << res << endl;
    return 0;
}
