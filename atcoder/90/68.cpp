#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

class UnionFind {
    int n;
    vector<int> parent, rank;

   public:
    UnionFind(int n) : n(n), parent(n), rank(n, 1) {
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
            if (rank[rootA] == rank[rootB]) {
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
    vector<int> T(Q), X(Q), Y(Q);
    vector<ll> V(Q);
    rep(i, Q) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        X[i]--;
        Y[i]--;
    }

    vector<ll> sum(N - 1, 0);
    rep(i, Q) {
        if (T[i] == 0) {
            sum[X[i]] = V[i];
        }
    }

    vector<ll> potential(N, 0);
    rep(i, N - 1) { potential[i + 1] = sum[i] - potential[i]; }

    UnionFind uf(N);
    rep(i, Q) {
        int t = T[i], x = X[i], y = Y[i];
        ll v = V[i];
        if (t == 0) {
            uf.unite(x, y);
        } else {
            if (uf.find(x) != uf.find(y)) {
                cout << "Ambiguous" << endl;
                continue;
            }
            ll diff = V[i] - potential[X[i]];
            if ((X[i] + Y[i]) % 2) {
                cout << potential[Y[i]] - diff << endl;
                continue;
            } else {
                cout << potential[Y[i]] + diff << endl;
                continue;
            }
        }
    }

    return 0;
}
