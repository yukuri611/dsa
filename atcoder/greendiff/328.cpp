#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Union-Findデータ構造
struct UnionFind {
    std::vector<int> par;
    UnionFind(int n) : par(n, -1) {}
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (par[rx] > par[ry]) std::swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int main() {
    int N, M;
    long long K;
    std::cin >> N >> M >> K;

    std::vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
        // 頂点番号を0-indexedに調整
        edges[i].u--;
        edges[i].v--;
    }

    long long min_cost = -1;  // or a very large value

    // ステップ1: ビット全探索で辺の組み合わせを列挙
    for (int i = 0; i < (1 << M); ++i) {
        // C++20なら std::popcount(i)
        if (__builtin_popcount(i) != N - 1) {
            continue;
        }

        std::vector<Edge> current_edges;
        long long current_weight_sum = 0;
        for (int j = 0; j < M; ++j) {
            if ((i >> j) & 1) {  // j番目のビットが1なら、j番目の辺を選ぶ
                current_edges.push_back(edges[j]);
                current_weight_sum += edges[j].w;
            }
        }

        // ステップ2: Union-Findで全域木か判定
        UnionFind uf(N);
        for (const auto& edge : current_edges) {
            uf.unite(edge.u, edge.v);
        }

        int components = 0;
        for (int v = 0; v < N; ++v) {
            if (uf.par[v] < 0) {
                components++;
            }
        }

        if (components == 1) {  // 連結成分が1つなら全域木
            // ステップ3: コストを計算して最小値を更新
            long long current_cost = current_weight_sum % K;
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    std::cout << min_cost << std::endl;

    return 0;
}
