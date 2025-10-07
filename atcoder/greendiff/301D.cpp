#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll binary_to_ll(string s) {
    ll res = 0;
    ll curr = 1;
    rep(i, s.size()) {
        res += (s[s.size() - 1 - i] - '0') * curr;
        curr *= 2;
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    ll N;
    cin >> N;

    string all0 = S;
    rep(i, S.size()) {
        if (all0[i] == '?') all0[i] = '0';
    }

    if (N < binary_to_ll(all0)) {
        cout << -1 << endl;
        return 0;
    }

    string curr = all0;
    rep(i, S.size()) {
        if (S[i] == '?') {
            string temp = curr;
            temp[i] = '1';
            if (binary_to_ll(temp) <= N) {
                curr[i] = '1';
            } else {
                curr[i] = '0';
            }
        }
    }

    cout << binary_to_ll(curr) << endl;
    return 0;
}
