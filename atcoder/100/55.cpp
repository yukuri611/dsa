#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] = -A[i];
    }

    vector<int> LIS;
    rep(i, N) {
        auto it = upper_bound(LIS.begin(), LIS.end(), A[i]);
        if (it == LIS.end())
            LIS.push_back(A[i]);
        else {
            *it = A[i];
        }
    }

    cout << LIS.size() << endl;
    return 0;
}
