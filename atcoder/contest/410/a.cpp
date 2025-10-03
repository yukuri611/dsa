#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int K;
    cin >> K;

    int ans = 0;
    rep(i, N) {
        if (K <= A[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
