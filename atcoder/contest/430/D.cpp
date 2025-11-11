#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void update(int i, int j, ll x_i, ll x_j, vector<ll>& dist, ll& total_dist) {
    // dist[i]とdist[j]をabs(x_i - x_j)で更新を試みる
    ll new_d = abs(x_i - x_j);
    if (dist[i] > new_d) {
        if (dist[i] != LLONG_MAX) {
            total_dist -= dist[i];
        }
        total_dist += new_d;
        dist[i] = new_d;
    }
    if (dist[j] > new_d) {
        if (dist[j] != LLONG_MAX) {
            total_dist -= dist[j];
        }
        total_dist += new_d;
        dist[j] = new_d;
    }
}

ll solve(int cur_i, ll cur_x, set<pair<ll, int>>& sorted_X, vector<ll>& dist,
         ll& total_dist) {
    auto it = sorted_X.lower_bound({cur_x, 0});
    if (it != sorted_X.end()) {
        ll x_j = it->first;
        int j = it->second;
        update(cur_i, j, cur_x, x_j, dist, total_dist);
    }
    if (it != sorted_X.begin()) {
        ll x_j = prev(it)->first;
        int j = prev(it)->second;
        update(cur_i, j, cur_x, x_j, dist, total_dist);
    }

    return total_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    set<pair<ll, int>> sorted_X;
    sorted_X.insert({0, 0});

    vector<ll> dist(N + 1, LLONG_MAX);
    ll total_dist = 0;
    vector<ll> res_list;
    for (int i = 1; i <= N; ++i) {
        ll cur_x;
        cin >> cur_x;
        ll res = solve(i, cur_x, sorted_X, dist, total_dist);
        res_list.push_back(res);
        sorted_X.insert({cur_x, i});
    }

    for (ll res : res_list) cout << res << endl;
    return 0;
}
