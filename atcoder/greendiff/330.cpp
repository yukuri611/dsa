#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> I(Q), X(Q);
    rep(i, Q) {
        cin >> I[i] >> X[i];
        I[i]--;
    }

    map<ll, int> Map;
    rep(i, N) Map[A[i]]++;

    set<int> Set;
    rep(i, N + 1) {  // サイズNのvector Aのmexは、最大でN。
        if (Map[i] == 0) Set.insert(i);
    }

    rep(i, Q) {
        Map[A[I[i]]]--;
        if (Map[A[I[i]]] == 0) Set.insert(A[I[i]]);
        A[I[i]] = X[i];
        Map[X[i]]++;
        if (Map[X[i]] == 1) Set.erase(X[i]);
        int res = *Set.begin();
        cout << res << endl;
    }

    return 0;
}
