#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

double f(double P, double x) { return x + P / pow(2, x / 1.5); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double P;
    cin >> P;

    double l = 0, r = P;

    rep(i, 50000000) {
        double mid1 = (l + l + r) / 3;
        double mid2 = (l + r + r) / 3;
        if (f(P, mid1) < f(P, mid2))
            r = mid2;
        else
            l = mid1;
    }

    cout << fixed << setprecision(8) << f(P, l) << endl;
    return 0;
}
