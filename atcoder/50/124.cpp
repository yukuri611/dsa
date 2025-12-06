#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, G, E;
    cin >> N >> G >> E;
    vector<int> P(N);
    rep(i, G) cin >> P[i];

    mf_graph<int> Graph(N + 1);
    rep(i, E) {
        int a, b;
        cin >> a >> b;
        Graph.add_edge(a, b, 1);
        Graph.add_edge(b, a, 1);
    }
    rep(i, G) {
        Graph.add_edge(P[i], N, 1);
        Graph.add_edge(N, P[i], 1);
    }

    int s = 0, t = N;
    int ans = Graph.flow(s, t);

    cout << ans << endl;
    return 0;
}
