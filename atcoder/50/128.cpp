#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) { cin >> A[i] >> B[i]; }
    rep(i, N) { cin >> C[i] >> D[i]; }

    int s = 0, t = 2 * N + 1;
    mf_graph<int> G(t + 1);
    rep(i, N) {
        int u = i + 1;
        int a = A[i], b = B[i];
        rep(j, N) {
            int v = N + 1 + j;
            int c = C[j], d = D[j];
            if (a < c && b < d) {
                G.add_edge(u, v, 1);
            }
        }
    }
    rep(i, N) { G.add_edge(s, i + 1, 1); }
    rep(i, N) { G.add_edge(N + 1 + i, t, 1); }

    int ans = G.flow(s, t);
    cout << ans << endl;
}
