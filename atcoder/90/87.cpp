#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<ll>> dist;
vector<vector<ll>> A;
int N, P, K;

int cnt(int x) {
    rep(i, N) rep(j, N) {
        if (A[i][j] == -1)
            dist[i][j] = x;
        else
            dist[i][j] = A[i][j];
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
        }
    }

    int res = 0;
    rep(i, N) for (int j = i + 1; j < N; ++j) {
        if (dist[i][j] <= P) res++;
    }
    return res;
}

ll solve(int k) {
    ll l = 0, r = 2e9 + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (cnt(mid) >= k)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    // input
    cin >> N >> P >> K;
    A.resize(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    dist.resize(N, vector<ll>(N));

    // solve
    ll L = solve(K + 1);  // K + 1個であるための最小値
    ll R = solve(K);      // K個であるための最小値

    if (R - L > 1e9)
        cout << "Infinity" << endl;
    else
        cout << R - L << endl;
    return 0;
}
