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

    int N, M;
    cin >> N >> M;
    UnionFind uf(N + 1);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }
    int K;
    cin >> K;
    vector<set<int>> vec(N + 1);
    rep(i, K) {
        int x, y;
        cin >> x >> y;
        int rootX = uf.find(x), rootY = uf.find(y);
        vec[rootX].insert(rootY);
        vec[rootY].insert(rootX);
    }
    int cnt;
    cin >> cnt;
    vector<int> P(cnt), Q(cnt);
    rep(i, cnt) cin >> P[i] >> Q[i];

    rep(i, cnt) {
        int p = P[i], q = Q[i];
        int rootP = uf.find(p), rootQ = uf.find(q);
        if (vec[rootP].find(rootQ) != vec[rootP].end())
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}
