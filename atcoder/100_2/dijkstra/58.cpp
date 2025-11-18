#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, S;
    cin >> N >> M >> K >> S;
    ll P, Q;
    cin >> P >> Q;

    set<int> Zombies;
    rep(i, K) {
        int c;
        cin >> c;
        c--;
        Zombies.insert(c);
    }

    vector<vector<int>> G2(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G2[a].push_back(b);
        G2[b].push_back(a);
    }

    set<int> Dangerous;
    queue<int> q;
    for (int c : Zombies) q.push(c);
    rep(d, S) {
        int length = q.size();
        rep(_, length) {
            int c = q.front();
            q.pop();
            for (int nc : G2[c]) {
                if (Dangerous.count(nc) == 1) continue;
                Dangerous.insert(nc);
                q.push(nc);
            }
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, 0});
    vector<ll> dist(N, LLONG_MAX);
    dist[0] = 0;
    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (dist[node] != cost) continue;
        if (node == N - 1) {
            cout << cost << endl;
            return 0;
        }
        for (int nxt_node : G2[node]) {
            if (Zombies.count(nxt_node)) continue;
            ll nxt_cost = cost;
            if (nxt_node != N - 1) {
                if (Dangerous.count(nxt_node))
                    nxt_cost += Q;
                else
                    nxt_cost += P;
            }
            if (dist[nxt_node] > nxt_cost) {
                dist[nxt_node] = nxt_cost;
                pq.push({nxt_cost, nxt_node});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
