#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if (X - Z * Y < 0)
        cout << "No" << endl;
    else if ((X - Z * Y) % (Z - 1) != 0) {
        cout << "No" << endl;
    } else
        cout << "Yes" << endl;
    return 0;
}
