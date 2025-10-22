#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dh = {1, 0, -1, 0};
vector<int> dw = {0, 1, 0, -1};
ll mod = 998244353;

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

ll powerMod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}

ll inverseMod(ll n) { return powerMod(n, mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    UnionFind uf(H * W);

    rep(i, H * W) {
        int h = i / W;
        int w = i % W;
        if (S[h][w] == '.') continue;
        rep(j, 4) {
            int nh = h + dh[j], nw = w + dw[j];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (S[nh][nw] == '.') continue;
            uf.unite(i, nh * W + nw);
        }
    }

    ll original = 0;
    rep(i, H * W) {
        int h = i / W;
        int w = i % W;
        if (S[h][w] == '#' && uf.find(i) == i) original++;
    }

    ll cnt = 0, unite_cnt = 0;
    rep(i, H * W) {
        int h = i / W;
        int w = i % W;
        if (S[h][w] == '#') continue;
        set<int> Set;
        rep(i, 4) {
            int nh = h + dh[i], nw = w + dw[i];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (S[nh][nw] == '.') continue;
            Set.insert(uf.find(nh * W + nw));
        }
        unite_cnt += original - (Set.size() - 1);
        unite_cnt %= mod;
        cnt++;
    }

    cout << (unite_cnt * inverseMod(cnt)) % mod << endl;
    return 0;
}
