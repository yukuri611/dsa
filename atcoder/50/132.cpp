#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

class BinaryIndexedTree {
   private:
    int n;
    vector<ll> tree;

   public:
    BinaryIndexedTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void add(int i, int x) {
        while (i <= n) {
            tree[i] += x;
            i += (i & -i);
        }
    }

    ll sum(int i) {
        ll s = 0;
        while (i > 0) {
            s += tree[i];
            i -= (i & -i);
        }
        return s;
    }

    ll getSum(int s, int t) { return sum(t) - sum(s - 1); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> Com(q), X(q), Y(q);
    rep(i, q) { cin >> Com[i] >> X[i] >> Y[i]; }

    BinaryIndexedTree Bit(n);
    rep(i, q) {
        int com = Com[i], x = X[i], y = Y[i];
        if (com == 0)
            Bit.add(x, y);
        else {
            int ans = Bit.getSum(x, y);
            cout << ans << endl;
        }
    }
    return 0;
}
