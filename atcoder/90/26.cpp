#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<int> color;
vector<vector<int>> G;

void dfs(int u, int c) {
    color[u] = c;
    for (int v : G[u]) {
        if (color[v] != -1) continue;
        dfs(v, 1 - c);
    }
}

int main() {
    // 木は二部グラフである。よって、二つの色で塗っていき、多いほうの色で塗られたノードをN/2個出力すればよい。
    int N;
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N, -1);
    dfs(0, 0);

    int sum = 0;
    rep(i, N) sum += color[i];
    if (sum >= N / 2) {
        // 1が多い。
        int c = 0;
        for (int i = 0; i < N && c < N / 2; ++i) {
            if (color[i]) {
                cout << i + 1 << " ";
                c++;
            }
        }
        cout << endl;
    } else {
        // 0が多い
        int c = 0;
        for (int i = 0; i < N && c < N / 2; ++i) {
            if (color[i] == 0) {
                cout << i + 1 << " ";
                c++;
            }
        }
        cout << endl;
    }

    return 0;
}
