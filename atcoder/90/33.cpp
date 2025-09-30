#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int H, W;
    cin >> H >> W;
    if (H < 2)
        cout << W << endl;
    else if (W < 2)
        cout << H << endl;
    else
        cout << (H / 2 + H % 2) * (W / 2 + W % 2) << endl;
    return 0;
}
