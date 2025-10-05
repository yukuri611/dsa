#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int H, W;
    cin >> H >> W;
    if (H == 1) {
        cout << W << endl;
        return 0;
    }
    if (W == 1) {
        cout << H << endl;
        return 0;
    } else {
        cout << ((W + 1) / 2) * ((H + 1) / 2) << endl;
        return 0;
    }
}
