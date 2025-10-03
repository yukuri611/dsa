#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> B(N, 0);
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    rep(_, Q) {
        int x = X[_];
        if (x == 0) {
            int minimum = INT_MAX;
            rep(i, N) { minimum = min(minimum, B[i]); }
            rep(i, N) {
                if (B[i] == minimum) {
                    cout << i + 1 << " ";
                    B[i]++;
                    break;
                }
            }
        } else {
            cout << x << " ";
            B[x - 1]++;
        }
    }
    cout << endl;

    return 0;
}
