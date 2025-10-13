#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, vector<ll>> Map;
    rep(i, N) Map[A[i]].push_back(i);

    
    ll res = 0;
    for(auto & [n, v]: Map) {
        int s = v.size();
        vector<ll> B(s + 1);
        B[0] = 0;
        for (int i = 0; i < s; ++i) B[i + 1] = B[i] + (v[i] - i);
        for (int i = 0; i < s; ++i) {
            // 1. (v[j] - j) の j=i+1..s-1 についての和
            ll sum_j_part = B[s] - B[i + 1];

            // 2. (v[i] - i) の j=i+1..s-1 についての和
            //    これは (v[i] - i) が (s - 1 - i) 回足されるのと同じ
            ll term_i = v[i] - i;
            ll num_j = s - 1 - i;
            if (num_j <= 0) continue; // jが存在しない場合は何もしない

            ll sum_i_part = num_j * term_i;

            // 1. から 2. を引いたものが、この i についての合計値
            res += sum_j_part - sum_i_part;
        }
    }

    cout << res << endl;
    return 0;
}
