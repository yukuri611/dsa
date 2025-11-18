#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int r = 0;
    ll cur_sum = 0;
    ll res = 0;
    rep(l, N) {
        while (r < N && ((cur_sum + A[r]) == (cur_sum ^ A[r]))) {
            cur_sum += A[r];
            r++;
        }
        res += r - l;
        if (r == l) r++;
        cur_sum -= A[l];
    }

    cout << res << endl;
    return 0;
}
