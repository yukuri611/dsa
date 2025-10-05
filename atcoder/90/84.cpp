#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> memoO(N + 1), memoX(N + 1);
    memoO[0] = memoX[0] = -1;
    rep(i, N) {
        if (S[i] == 'o') {
            memoO[i + 1] = i;
            memoX[i + 1] = memoX[i];
        }
        if (S[i] == 'x') {
            memoO[i + 1] = memoO[i];
            memoX[i + 1] = i;
        }
    }

    ll res = 0;
    rep(i, N) {
        if (S[i] == 'o') {
            ll j = memoX[i] + 1;
            res += j;
        } else {
            ll j = memoO[i] + 1;
            res += j;
        }
    }

    cout << res << endl;
    return 0;
}
