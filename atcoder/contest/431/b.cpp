#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;
    int N;
    cin >> N;
    vector<int> W(N);
    rep(i, N) cin >> W[i];
    int Q;
    cin >> Q;
    vector<int> P(Q);
    rep(i, Q) {
        cin >> P[i];
        P[i]--;
    }

    int weight = X;
    vector<bool> isOn(Q, false);
    rep(i, Q) {
        int p = P[i];
        if (isOn[p]) {
            isOn[p] = false;
            weight -= W[p];
            cout << weight << endl;
        } else {
            isOn[p] = true;
            weight += W[p];
            cout << weight << endl;
        }
    }

    return 0;
}
