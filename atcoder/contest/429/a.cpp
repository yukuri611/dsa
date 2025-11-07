#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i < N + 1; ++i) {
        if (i <= M) {
            cout << "OK" << endl;
        } else {
            cout << "Too Many Requests" << endl;
        }
    }
    return 0;
}
