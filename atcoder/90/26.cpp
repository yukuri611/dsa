#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> color(N, -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (color[v] != -1) continue;
            color[v] = 1 - color[u];
            q.push(v);
        }
    }

    int cnt0 = 0;
    int cnt1 = 0;
    rep(i, N) {
        if (color[i] == 0)
            cnt0++;
        else
            cnt1++;
    }

    if (cnt0 >= cnt1) {
        int c = 0;
        rep(i, N) {
            if (color[i] == 0) {
                cout << i + 1 << " ";
                c++;
                if (c == N / 2) break;
            }
        }
    } else {
        int c = 0;
        rep(i, N) {
            if (color[i] == 1) {
                cout << i + 1 << " ";
                c++;
                if (c == N / 2) break;
            }
        }
    }
    cout << endl;

    return 0;
}
