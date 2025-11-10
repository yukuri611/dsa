#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<ll> solve(const vector<ll>& top, const vector<ll>& bottom,
                 vector<ll>& total_sum) {
    int N = top.size();
    vector<ll> res(N + 1, 0);
    rep(i, N) {
        ll index =
            upper_bound(bottom.begin(), bottom.end(), top[i]) - bottom.begin();
        ll cnt = total_sum.back() - total_sum[index];
        res[i + 1] = res[i] + cnt;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<ll> total_sum(N + 1);
    iota(total_sum.begin(), total_sum.end(), 0);

    total_sum = solve(B, C, total_sum);
    total_sum = solve(A, B, total_sum);

    cout << total_sum.back() << endl;
    return 0;
}
