#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int prevX = -1, prevO = -1;
    ll res = 0;
    rep(i, N) {
        if (S[i] == 'o') {
            prevO = i;
            res += prevX + 1;
        } else {
            prevX = i;
            res += prevO + 1;
        }
    }

    cout << res << endl;
    return 0;
}
