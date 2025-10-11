#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    map<int, int> M;
    set<ll> S;
    for (int i = 1; i <= N; ++i) {
        int a = A[i];
        M[a]++;
    }
    rep(i, N + 1) {
        if (M[i] == 0) S.insert(i);
    }

    rep(j, Q) {
        int i, x;
        cin >> i >> x;
        M[A[i]]--;
        if (M[A[i]] == 0) S.insert(A[i]);
        A[i] = x;
        M[x]++;
        if (M[x] == 1) S.erase(x);

        cout << *S.begin() << endl;
        }
}
