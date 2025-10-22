#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> solve(vector<int>& vec) {
    vector<int> res(vec.size());
    res[0] = 1;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > res[i - 1])
            res[i] = res[i - 1] + 1;
        else
            res[i] = vec[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    auto HeightL = solve(A);
    reverse(A.begin(), A.end());
    auto HeightR = solve(A);

    int res = 0;
    rep(i, N) {
        int h = min(HeightL[i], HeightR[N - 1 - i]);
        res = max(res, h);
    }
    cout << res << endl;
    return 0;
}
