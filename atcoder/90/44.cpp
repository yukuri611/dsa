#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int s = 0;
    vector<int> res_list;
    rep(_, Q) {
        int T;
        cin >> T;
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (T == 1) {
            x = (x + s) % N;
            y = (y + s) % N;
            swap(A[x], A[y]);
        } else if (T == 2) {
            s = (s - 1 + N) % N;
        } else {
            x = (x + s) % N;
            res_list.push_back(A[x]);
        }
    }
    for (int res : res_list) cout << res << endl;
    return 0;
}
