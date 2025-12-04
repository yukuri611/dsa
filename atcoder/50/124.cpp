#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, G, E;
    cin >> N >> G >> E;
    vector<int> P(G);
    rep(i, G) cin >> P[i];

    mf_graph<int> graph(N + 1);

    rep(i, E) {
        int a, b;
        cin >> a >> b;
        graph.add_edge(a, b, 1);
        graph.add_edge(b, a, 1);
    }
    for (auto p : P) {
        graph.add_edge(p, N, 1);
    }

    cout << graph.flow(0, N) << endl;
    return 0;
}
