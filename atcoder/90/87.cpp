#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll N, P, K;
vector<vector<ll>> A;

ll countPath(ll x) {
    // ワーシャルフロイドを使用。
    vector<vector<ll>> dist(N, vector<ll>(N, 0));
    rep(i, N) rep(j, N) {
        if (A[i][j] == -1)
            dist[i][j] = x;
        else
            dist[i][j] = A[i][j];
    }
    rep(i, N) {
        rep(j, N) {
            rep(k, N) { dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]); }
        }
    }

    // kで行けるパスの総数をカウント
    ll res = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            if (dist[i][j] <= P) res++;
        }
    }

    return res;
}

ll solve(ll k) {
    // パスの総数がk以上となる、最大のxを返す。
    ll l = 0;
    ll r = P + 2;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        ll cnt = countPath(mid);
        if (cnt >= k)
            l = mid;
        else
            r = mid;
    }

    return l;
}

int main() {
    cin >> N >> P >> K;
    A.resize(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    ll R = solve(K);
    ll L = solve(K + 1);
    if (R == P + 1 && L == 0) {
        cout << "Infinity" << endl;
    } else {
        cout << R - L << endl;
    }
}
