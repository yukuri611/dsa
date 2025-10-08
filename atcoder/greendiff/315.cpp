#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<int>> G;

vector<int> Cnt;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    G.resize(N + 1);
    Cnt.resize(N + 1);
    for (int i = 1; i < N + 1; ++i) {
        int c; cin >> c;
        rep(j, c) {
            int p; cin >> p;
            G[p].push_back(i);
        }
        Cnt[i] = c;
    }

    queue<int> q;
    for (int i = 1; i < N + 1; ++i) {
        if (Cnt[i] == 0) q.push(i);
    }

    vector<int> res_list;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        res_list.push_back(u);
        for (int v: G[u]) {
            Cnt[v]--;
            if(Cnt[v] == 0) q.push(v);
        }
    }

    rep(i, res_list.size()) {
        int res = res_list[i];
        if (res == 1) break;
        cout << res << " ";
    }

    cout << endl;
    return 0;

}
