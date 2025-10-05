#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

double PI = acos(-1);

int main() {
    ll T;
    cin >> T;
    ll L, X, Y;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    cout << fixed << setprecision(7);
    rep(_, Q) {
        ll E;
        cin >> E;
        double theta = (2 * PI) / T * E;
        double h = (1 - cos(theta)) * L / 2;
        double a = -(L * sin(theta)) / 2;
        double base = sqrt(X * X + (Y - a) * (Y - a));
        double phi = atan(h / base) * 180 / PI;
        cout << phi << endl;
    }
    return 0;
}
