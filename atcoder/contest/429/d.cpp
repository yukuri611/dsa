#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, C;
    cin >> N >> M >> C;
    map<ll, ll> Map;
    rep(i, N) {
        ll a;
        cin >> a;
        Map[a]++;
        Map[a + M]++;
    }

    vector<ll> A;
    for (auto [pos, cnt] : Map) {
        A.push_back(pos);
    }

    ll res = 0;
    ll cnt = 0;
    int il = 0, ir = 0;
    while (cnt < C) {
        cnt += Map[A[ir++]];
    }
    res += (A[0] - (-1)) * cnt;
    cnt -= Map[A[0]];
    il++;

    while (A[il + 1] < M) {
        while (cnt < C) {
            cnt += Map[A[ir++]];
        }
        res += (A[il + 1] - A[il]) * cnt;
        cnt -= Map[A[il + 1]];
        il++;
    }
    while (cnt < C) {
        cnt += Map[A[ir++]];
    }
    res += (M - A[il]) * cnt;

    cout << res << endl;
    return 0;
}
