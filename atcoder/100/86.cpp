#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    int ans = 0;
    rep(bridge, M) {
        dsu uf(N);
        rep(i, M) {
            if (i == bridge) continue;
            uf.merge(A[i], B[i]);
        }
        int a = A[bridge], b = B[bridge];
        if (!uf.same(a, b)) ans++;
    }
    cout << ans << endl;
    return 0;
}
