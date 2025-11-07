#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    int q;
    cin >> q;
    vector<int> M(q);
    rep(i, q) cin >> M[i];

    set<int> all_sum;
    rep(i, (1 << n)) {
        int sum = 0;
        rep(j, n) {
            if ((i & (1 << j))) sum += A[j];
        }
        all_sum.insert(sum);
    }
    rep(i, q) {
        int m = M[i];
        if (all_sum.count(m) == 1) {
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;
    }

    return 0;
}
