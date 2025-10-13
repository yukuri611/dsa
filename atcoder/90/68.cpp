#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

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
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<ll> T(Q), X(Q), Y(Q), V(Q);
    rep(i, Q) cin >> T[i] >> X[i] >> Y[i] >> V[i];

    vector<ll> sum(N, 0);
    rep(i, Q) {
        if (T[i] == 0) {
            sum[X[i]] = V[i];
        }
    }

    vector<ll> potential(N + 1, 0);
    for (int i = 1; i < N; ++i) {
        potential[i + 1] = sum[i] - potential[i];
    }

    UnionFind uf(N + 1);
    rep(i, Q) {
        int t = T[i], x = X[i], y = Y[i];
        ll v = V[i];
        if (t == 0) {
            uf.unite(x, y);
        } else {
            if (uf.find(x) != uf.find(y)) {
                cout << "Ambiguous" << endl;
            } else {
                ll diff = v - potential[x];
                if ((y + x) % 2) {
                    cout << potential[y] - diff << endl;
                } else {
                    cout << potential[y] + diff << endl;
                }
            }
        }
    }

    return 0;
}
