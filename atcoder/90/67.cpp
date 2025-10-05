#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll base8_to_ll(string N) {
    ll res = 0;
    ll curr = 1;
    rep(i, N.size()) {
        res += ((N[N.size() - 1 - i]) - '0') * curr;
        curr *= 8;
    }
    return res;
}

string ll_to_base9(ll N) {
    if (N == 0) return "0";
    string ans;
    while (N > 0) {
        ans += '0' + (N % 9);
        N /= 9;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string N;
    cin >> N;
    int K;
    cin >> K;

    rep(i, K) {
        ll N_ll = base8_to_ll(N);
        N = ll_to_base9(N_ll);
        rep(i, N.size()) {
            if (N[i] == '8') N[i] = '5';
        }
    }

    cout << N << endl;
    return 0;
}
