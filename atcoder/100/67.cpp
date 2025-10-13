#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Edge {
    ll cost;
    int u, v;

    bool operator<(const Edge& e) const { return cost < e.cost; }
    bool operator>(const Edge& e) const { return cost > e.cost; }
};

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

    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<ll> indexX(N);
    iota(indexX.begin(), indexX.end(), 0);
    sort(indexX.begin(), indexX.end(),
         [&](int i, int j) { return X[i] < X[j]; });
    vector<ll> indexY(N);
    iota(indexY.begin(), indexY.end(), 0);
    sort(indexY.begin(), indexY.end(),
         [&](int i, int j) { return Y[i] < Y[j]; });

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    rep(i, N - 1) {
        int i1 = indexX[i], i2 = indexX[i + 1];
        pq.push({X[i2] - X[i1], i1, i2});
    }
    rep(i, N - 1) {
        int i1 = indexY[i], i2 = indexY[i + 1];
        pq.push({Y[i2] - Y[i1], i1, i2});
    }

    UnionFind uf(N);
    ll res = 0;
    while (!pq.empty()) {
        auto [cost, u, v] = pq.top();
        pq.pop();
        if (uf.find(u) == uf.find(v)) continue;
        uf.unite(u, v);
        res += cost;
    }

    cout << res << endl;
    return 0;
}
