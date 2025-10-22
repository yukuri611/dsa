#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<set<int>> st(N);
    rep(i, N) {
        int c;
        cin >> c;
        st[i].insert(c);
    }
    vector<int> A(Q), B(Q);
    rep(i, Q) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    rep(i, Q) {
        int a = A[i], b = B[i];
        if (st[a].size() < st[b].size()) {
            // 普通にaからbに移動する。
            for (int ball : st[a]) {
                st[b].insert(ball);
            }
            st[a].clear();
        } else {
            // bからa移動して、setをスワップ。
            for (int ball : st[b]) {
                st[a].insert(ball);
            }
            st[b].clear();
            swap(st[a], st[b]);
        }

        cout << st[b].size() << endl;
    }

    return 0;
}
