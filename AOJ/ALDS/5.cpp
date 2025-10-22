#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int c = 0;
    rep(i, N) {
        rep(j, N - 1) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                c++;
            }
        }
    }

    rep(i, N) {
        cout << A[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl << c << endl;
    return 0;
}
