#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll baseT_to_long(string a, int t) {
    ll res = 0;
    rep(i, a.size()) {
        int digit = int(a[i] - '0');
        res = res * t + digit;
    }
    return res;
}

string long_to_baseT(ll a, int t) {
    if (a == 0) return "0";  // これがないと、空文字を返すことになってしまう。
    string res = "";
    while (a > 0) {
        res += char(a % t + '0');
        a /= t;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string N;
    int K;
    cin >> N >> K;

    string ans = N;
    rep(i, K) {
        ll currNum = baseT_to_long(ans, 8);
        ans = long_to_baseT(currNum, 9);
        rep(j, ans.size()) {
            if (ans[j] == '8') ans[j] = '5';
        }
    }
    cout << ans << endl;
    return 0;
}
