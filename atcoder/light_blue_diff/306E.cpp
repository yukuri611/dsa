#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> X(Q), Y(Q);
    rep(i, Q) { cin >> X[i] >> Y[i]; }

    vector<int> A(N + 1, 0);
    multiset<ll> S, T;
    rep(i, K) S.insert(0);
    rep(i, N - K) T.insert(0);
    ll f = 0;

    rep(i, Q) {
        ll x = X[i], y = Y[i];
        T.insert(y);
        if (T.find(A[x]) != T.end()) {
            T.erase(T.find(A[x]));
        } else if (S.find(A[x]) != S.end()) {
            S.erase(S.find(A[x]));
            f -= A[x];
        }
        A[x] = y;
        ll Smin = *S.begin();
        ll Tmax = *T.rbegin();
        if (S.size() < K) {
            T.erase(T.find(Tmax));
            S.insert(Tmax);
            f += Tmax;
        }
        Smin = (S.size() > 0) ? *S.begin() : 1e18;
        Tmax = (T.size() > 0) ? *T.rbegin() : -1;
        if (Smin < Tmax) {
            T.erase(T.find(Tmax));
            S.insert(Tmax);
            S.erase(S.find(Smin));
            T.insert(Smin);
            f += (Tmax - Smin);
        }
        cout << f << endl;
    }

    return 0;
}
