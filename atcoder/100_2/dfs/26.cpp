#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void dfs(int curr, int parent, const vector<vector<int>>& Tree,
         vector<ll>& cnt) {
    for (int child : Tree[curr]) {
        if (child == parent) continue;
        cnt[child] += cnt[curr];
        dfs(child, curr, Tree, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> Tree(N + 1);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    vector<ll> cnt(N + 1, 0);
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        cnt[p] += x;
    }

    dfs(1, 0, Tree, cnt);

    for (int i = 1; i <= N; ++i) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}
