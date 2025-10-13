#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

class UnionFind {
    vector<int> parent, rank;

   public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

    void unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return;
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            if (rank[rootB] == rank[rootA]) {
                rank[rootA]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> U(M), V(M), W(M);
    rep(i, M) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--;
        V[i]--;
    }

    vector<int> use(M, false);
    rep(i, N - 1) use[M - N + 1 + i] = true;

    ll res = K;
    do {
        UnionFind uf(N);
        ll cost = K;
        rep(i, M) {
            if (use[i]) {
                if (uf.find(U[i]) == uf.find(V[i])) {
                    cost = K;
                    break;
                }
                uf.unite(U[i], V[i]);
                cost += W[i];
                cost %= K;
            }
        }
        res = min(res, cost);
    } while (next_permutation(use.begin(), use.end()));

    cout << res << endl;
    return 0;
}
