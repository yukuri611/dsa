#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int Q;
    cin >> Q;

    deque<int> deq;
    rep(i, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            deq.push_front(x);
        else if (t == 2)
            deq.push_back(x);
        else {
            x--;
            cout << deq[x] << endl;
        }
    }
    return 0;
}
