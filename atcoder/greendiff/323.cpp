#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    map<ll, int> Map;
    rep(i, N) {
        ll s;
        int c;
        cin >> s >> c;
        Map[s] = c;
    }

    ll res = 0;
    while (!Map.empty()) {
        auto it = Map.begin();
        if (it->second == 1) {
            res++;
        } else {
            if (it->second % 2) res++;
            Map[it->first * 2] += (it->second / 2);
        }
        Map.erase(it);
    }

    cout << res << endl;
    return 0;
}
