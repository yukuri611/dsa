#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

double PI = acos(-1);

int main() {
    double T; cin >> T;
    double L, X, Y; cin >> L >> X >> Y;
    double w = (2 * PI) / T;
    int Q; cin >> Q;
    cout << fixed << setprecision(10);
    rep(_, Q) {
        int e; cin >> e;
        double phi = w * e;
        double h = (L / 2) * (1 - cos(phi));
        double a = (-L / 2) * sin(phi);
        double theta = atan2(h, sqrt(pow(X,2) + pow(Y - a, 2)));
        cout << (180 / PI) * theta << endl; 
    }
    return 0;
}
