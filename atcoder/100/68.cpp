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

    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q);
    vector<ll> X(Q), Y(Q), V(Q);
    rep(i, Q) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        --X[i];
        --Y[i];
    }

    vector<ll> info(N - 1, -1);
    rep(i, Q) {
        if (T[i] == 0) {
            info[X[i]] = V[i];
        }
    }

    vector<ll> potential(N, 0);
    rep(i, N - 1) {
        if (info[i] != -1) {
            potential[i + 1] = info[i] - potential[i];
        }
    }

    UnionFind uf(N);

    rep(i, Q) {
        if (T[i] == 0) {
            uf.unite(X[i], Y[i]);
        } else {
            if (uf.find(X[i]) != uf.find(Y[i])) {
                cout << "Ambiguous" << endl;
            } else {
                ll diff = V[i] - potential[X[i]];
                if (abs(X[i] - Y[i]) % 2) {
                    cout << potential[Y[i]] - diff << endl;
                } else {
                    cout << potential[Y[i]] + diff << endl;
                }
            }
        }
    }

    return 0;
}
