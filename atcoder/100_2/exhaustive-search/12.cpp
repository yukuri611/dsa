#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<set<int>> relation(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        relation[x].insert(y);
        relation[y].insert(x);
    }

    int res = 0;
    rep(i, (1 << N)) {
        vector<int> member;
        rep(j, N) {
            if ((i >> j) & 1) member.push_back(j);
        }

        bool valid = true;
        rep(j, member.size()) {
            if (!valid) break;
            for (int k = j + 1; k < member.size(); ++k) {
                if (relation[member[j]].count(member[k]) == 0) valid = false;
            }
        }

        if (valid) res = max(res, (int)member.size());
    }

    cout << res << endl;
    return 0;
}
