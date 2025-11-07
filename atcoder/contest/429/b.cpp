#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int sum = 0;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }

    rep(i, N) {
        int a = A[i];
        if (sum - a == M) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
