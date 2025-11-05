#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;
    vector<int> D(N);
    rep(i, N) {
        int d;
        cin >> d;
        d %= (A + B);
        D[i] = d;
    }

    sort(D.begin(), D.end());
    int diff = D.back() - D[0];
    rep(i, N - 1) {
        int curr = A + B - (D[i + 1] - D[i]);
        diff = min(diff, curr);
    }
    if (diff < A)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
