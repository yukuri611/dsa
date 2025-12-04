#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        int id = -2;
        rep(j, i) {
            if (A[j] > A[i]) {
                id = j;
            }
        }
        cout << id + 1 << endl;
    }
    return 0;
}
