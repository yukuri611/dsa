#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);
    cout << a << b << c << endl;
    return 0;
}
