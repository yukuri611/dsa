#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    map<int, vector<int>> Map;
    rep(i, N) {
        int a;
        cin >> a;
        Map[a].push_back(i);
    }

    ll res = 0;
    for (auto& [a, vec] : Map) {
        int sz = vec.size();
        rep(i, sz) { res += (ll)(N - sz) * (sz - 1 - i); }
    }

    cout << res << endl;
    return 0;
}
