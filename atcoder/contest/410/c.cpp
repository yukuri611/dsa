#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
#define int ll
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) A[i] = (i + 1);
    int start = 0;

    vector<int> res_list;
    rep(_, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            A[(p + start) % N] = x;
        } else if (f == 2) {
            int p;
            cin >> p;
            p--;
            int index = (start + p) % N;
            res_list.push_back(A[index]);
        } else {
            int k;
            cin >> k;
            k %= N;
            start += k;
            start %= N;
        }
    }

    for (int res : res_list) cout << res << endl;
    return 0;
}
