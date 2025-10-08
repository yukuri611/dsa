#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> X(Q), Y(Q), Z(Q);
    vector<ll> W(Q);
    rep(i, Q) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--; Y[i]--; Z[i]--;
    }

    int M = 60;
    ll res = 1;
    rep(i, M) {
        // Now looking at bit[i]
        int c = 0;
        rep(s, (1 << N)) {
            bool valid = true;
            rep(j, Q) {
                int OR = ((s >> X[j]) & 1) | ((s >> Y[j]) & 1) | ((s >> Z[j]) & 1);
                if (OR != ((W[j] >> i) & 1)) {
                    valid = false;
                    break;
                }
            }
            if (valid) c++;
        } 
        res = (res * c) % mod;
    }

    cout << res << endl;
    return 0;
}
