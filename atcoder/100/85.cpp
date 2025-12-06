#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

class UnionFind {
    vector<int> d;  //

   public:
    UnionFind(int n) { d.resize(n, -1); }

    int find(int a) {
        if (d[a] < 0) return a;
        return d[a] = find(d[a]);
    }

    void unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return;
        if (-d[rootA] < -d[rootB]) {
            swap(rootA, rootB);
        }
        d[rootA] += d[rootB];
        d[rootB] = rootA;
    }

    bool same(int a, int b) { return find(a) == find(b); }
    int size(int a) { return -d[find(a)]; }
};
int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<bool> res_list;
    rep(i, q) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        } else {
            res_list.push_back(uf.same(x, y));
        }
    }

    for (auto res : res_list) {
        if (res)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
