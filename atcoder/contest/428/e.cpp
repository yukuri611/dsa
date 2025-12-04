#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

void dfs(int cur, vector<vector<int>>& Tree, vector<int>& dist) {
    for (auto nxt : Tree[cur]) {
        if (dist[nxt] != -1) continue;
        dist[nxt] = dist[cur] + 1;
        dfs(nxt, Tree, dist);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> Tree(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    // double sweep
    vector<int> dist(N, -1);
    dist[0] = 0;
    dfs(0, Tree, dist);
    int a = 0;
    rep(i, N) if (dist[i] >= dist[a]) a = i;

    fill(dist.begin(), dist.end(), -1);
    dist[a] = 0;
    dfs(a, Tree, dist);
    int b = 0;
    rep(i, N) if (dist[i] >= dist[b]) b = i;

    // Aからの距離、Bからの距離をキャッシュしておく
    vector<int> distA(N, -1), distB(N, -1);
    distA[a] = 0;
    distB[b] = 0;
    dfs(a, Tree, distA);
    dfs(b, Tree, distB);

    rep(i, N) {
        if (distA[i] > distB[i])
            cout << a + 1 << endl;
        else if (distB[i] > distA[i])
            cout << b + 1 << endl;
        else
            cout << max(a, b) + 1 << endl;
    }

    return 0;
}
