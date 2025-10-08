#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
        }
        else {
            parent[rootB] = rootA;
            if (rank[rootB] == rank[rootA]) {
                rank[rootA]++;
            }
        }
    }
};

int main() {
    int N, M; cin >> N >> M;
    UnionFind uf(N + 1);
    rep(i, M) {
        int u, v; cin >> u >> v;
        uf.unite(u, v);
    }

    int K; cin >> K;
    vector<int> X(K), Y(K);
    rep(i, K) cin >> X[i] >> Y[i];

    set<pair<int, int>> Set;
    rep(i, K) {
        int x = X[i], y = Y[i];
        int rootX = uf.find(x), rootY = uf.find(y);
        Set.insert({rootX, rootY});
        Set.insert({rootY, rootX});
    }

    int Q; cin >> Q;
    rep(i, Q) {
        int p, q; cin >> p >> q;
        int rootP = uf.find(p), rootQ = uf.find(q);

        if (Set.find({rootP, rootQ}) == Set.end()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
