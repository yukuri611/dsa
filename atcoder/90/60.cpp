#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> v1(N);
    vector<int> LIS;
    rep(i, N) {
        int a = A[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), a);
        if (it == LIS.end())
            LIS.push_back(a);
        else
            *it = a;
        v1[i] = LIS.size();
    }
    vector<int> v2(N + 1, 0);
    LIS.clear();
    for (int i = N - 1; i > -1; --i) {
        int a = A[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), a);
        if (it == LIS.end())
            LIS.push_back(a);
        else
            *it = a;
        v2[i] = LIS.size();
    }
    int res = 0;
    rep(i, N) {
        if (i != N - 1 && A[i] == A[i + 1]) continue;
        res = max(res, v1[i] + v2[i + 1]);
    }

    cout << res << endl;
    return 0;
}
