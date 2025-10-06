#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<pair<int, int>> LIS1(N);
    vector<int> temp;
    rep(i, N) {
        auto it = lower_bound(temp.begin(), temp.end(), A[i]);
        if (it == temp.end()) temp.push_back(A[i]);
        int j = it - temp.begin();
        temp[j] = A[i];
        LIS1[i] = {j + 1, temp.back()};
    }

    vector<pair<int,int>> LIS2(N);
    temp.clear();
    for(int i = N-1; i >= 0; --i) {
        auto it = lower_bound(temp.begin(), temp.end(), A[i]);
        if (it == temp.end()) temp.push_back(A[i]);
        int j = it - temp.begin();
        temp[j] = A[i];
        LIS1[i] = {j + 1, temp.back()};
    }

    int res = 0;
    rep(i, N-1) {
        if (A[i] <= A[i + 1]) continue;
        res = max(res, LIS1[i].first + LIS2[i+1].first);
    }

    cout << res << endl;
    return 0;
}
